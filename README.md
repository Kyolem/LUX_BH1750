# LUX_BH1750
#### This is a library to use a BH1750 with many microcontroller who use Arduino and platformIO IDE.
#### I made this library with my friend Mathieu.
#### You have diffferent fonction with their uses :

` bool begin(uint8_t adress) ` 
This fonction is use to begin the transmission with the DS3231's adress.    
She return True for no problem and False if there is a problem.

` void setMode(uint8_t mode) `   
This fonction is use to set the mode.  
To set the actual Time you have to put a mode represented by :  
` BH1750_CONTINOUS_H_RES_MOD ` with value: 0x10, this is a continuous measurement with a resolution of 1 lux,  
` BH1750_CONTINOUS_H_RES2_MOD ` with value: 0x11, this is a continuous measurement with a resolution of 0.5 lux,  
` BH1750_CONTINOUS_L_RES_MOD ` with value: 0x13, this is a continuous measurement with a resolution of 4 lux,  
` BH1750_ONE_TIME_H_RES_MOD ` with value: 0x20, this is a One Time measurement with a resolution of 1 lux,  
` BH1750_ONE_TIME_H_RES2_MOD ` with value: 0x21, this is a One Time measurement with a resolution of 0.5 lux,  
` BH1750_ONE_TIME_L_RES_MOD ` with value: 0x23, this is a One Time measurement with a resolution of 4 lux  
> If you use a One Time mode make sure you use the PowerON() function before use readValue();  
> When you use Visual Studio Code and you try to put a mode Visual Studio propose you some solution   

` bool isMeasurementReady() `  
This fonction is use to know if you can read the value properly    
It return True if it's readyand False if it's not ready.  
> You can use readValue() function without this funciton but I don't promise a good result  

` void powerOn() `  
This fonction is use to launch a measurement.  
> You're obligate to put it before readValue() if you use One Time measurement mode.  

` void powerDown() `  
This fonction is use to stop ce sensor and put it in no active state mode.
> It automatically put after a One Time measurement 

` float readValue() `  
This fonction is use to read the value of luminosity.
She return the value into float.

## Thank's for downloading and help me to upgrade my libraries and my skills 👍
