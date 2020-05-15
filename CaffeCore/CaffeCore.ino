#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>

#include "config.h"

IPAddress machineIP(__ap_gateway__);
IPAddress machineSubnet(__ap_subnet__);
ESP8266WebServer webServer(__web_server_port__);
DNSServer dnsServer;

void hardwaretest(){
  digitalWrite(16,HIGH);
  pinMode(16,OUTPUT);
  initial();
  Serial.begin(115200);
  Serial.println("\nBooting...");

  for(int i=0;i<5;i++){
    digitalWrite(__indicator__,LOW);
    delay(500);
    digitalWrite(__indicator__,HIGH);
    delay(500);
  }
  Serial.println("RESETing...");
  digitalWrite(16,LOW);
  Serial.println("RESET not work!");
  for(int i=0;i<5;i++){
    digitalWrite(__indicator__,LOW);
    delay(500);
    digitalWrite(__indicator__,HIGH);
    delay(500);
  }
}


void setup() {
  hardwaretest();
//  WiFi.mode(WIFI_AP);
//  WiFi.softAPConfig(machineIP,machineIP,machineSubnet);
//  WiFi.softAP(__ap_ssid__);

  struct softap_config config;
  unsigned char macaddr[6];

  wifi_set_opmode(SOFTAP_MODE);
  wifi_softap_get_config(&config);

  os_memset(config.ssid, 0, 32);
//  os_memset(config.password, 0, 64);
  os_memcpy(config.ssid, __ap_ssid__, strlen(__ap_ssid__));
//  os_memcpy(config.password, __ap_password__, strlen(__ap_password__));
  config.authmode = AUTH_OPEN;//AUTH_WPA_WPA2_PSK;
  config.ssid_len = 0;
  config.beacon_interval = 100;
  config.max_connection = 1; 

  wifi_softap_set_config(&config);
  wifi_set_opmode(SOFTAP_MODE);
  wifi_softap_dhcps_start();

  dnsServer.start(__dns_server_port__,"*",machineIP);
  webServer.onNotFound([]() {
    webServer.send(200,"text/html",__machine_name__);
  });
  webServer.begin();
}

void loop() {
  dnsServer.processNextRequest();
  webServer.handleClient();
}
