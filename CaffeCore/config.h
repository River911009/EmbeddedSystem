/**
 * Config for espresso machine controller
 * created by Liao Riviere
 * at 16 March, 2020
 */
#ifndef __CONFIG_H__
#define __CONFIG_H__

// Basic information
#define __machine_name__    "GAGGIA Classic"



// Wireless config
#define __ap_ssid__         "GAGGIA Classic"
#define __ap_password__     ""

#define __ap_gateway__      192,168,4,1
#define __ap_subnet__       255,255,255,0

#define __dns_server_port__ 53
#define __web_server_port__ 80



// Hardware connection
#define __MAX6675_CK__      14
#define __MAX6675_CS__      12
#define __MAX6675_DO__      13
#define __heater__          15
#define __valve__           5
#define __pump__            4
#define __indicator__       2
#define __funcButton__      0


#endif
