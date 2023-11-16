# IV-Drip-Monitoring-Controlling-System-IOT

## Problem Statement
Intravenous therapy is treatment that infuses intravenous solutions directly into vein. It is an effective and fast acting way to administer fluid in an emergency situation, and for patients who are unable to take medications orally. IV drip system is commonly used in healthcare system; however, IV drip system need to be regularly monitored and replaced. In order to reduce the workload of nursing staff and overcome critical situations like backflow of blood, we proposed a system called Automated IV Monitoring and Control System based on IoT technology. The proposed system can overcome a number of problems during the IV therapy, which implies less patient concern and greater efficiency of medical staff with less effort and greater satisfaction.

## Hardware and Software 
1. NodeMCU ESP32 Controller
1. Load Cell
1. Load Cell Amplifier HX711
1. Servo Motor
1. Buzzer
1. Saline bottle
1. Blynk App

## Methodology
![image](https://github.com/vikashy53/IV-Drip-Monitoring-Controlling-System-IOT/assets/122713683/cce65e57-ad7e-4d5f-9c91-3ac2f8e8b101)

## Pictures
![WhatsApp Image 2023-11-16 at 17 02 27_b3d5082e](https://github.com/vikashy53/IV-Drip-Monitoring-Controlling-System-IOT/assets/122713683/31ceb5fb-7bce-4c0e-a668-dbba8d8b33ee)

## Conclusion
The system includes NodeMCU ESP32 Controller, Load Cell, Servo Motor with clam, Saline Bottle, Buzzer, and Blynk App. The system is designed to capture the changes in the level of saline bottle and determine the level of saline bottle which is continuously being displayed oven the blynk application. When the determined level is less than predefined threshold weight, then the buzzer sounds to notify the nursing staff and the supply of the fluid through the pipe to the patient is stopped. A warning is also issued on the blynk application.
