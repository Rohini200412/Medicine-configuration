 User-Configurable Medicine Reminder System

 Overview

This project is an embedded system designed to help users take medicines on time. It allows users to configure medicine schedules and generates alerts at the correct time using a buzzer and LCD display.

The system is built using LPC2148 (ARM7) microcontroller and uses RTC, interrupts, keypad input, and LCD display for user interaction.


 Features

- Real-Time Clock (RTC) based time tracking
-  LCD display for time and alerts
- 4x4 Matrix Keypad for user input
-  Buzzer alert for medicine reminder
- Interrupt-based control (EINT0 & EINT1)
- User-configurable medicine timings



 Hardware Components

- LPC2148 Microcontroller (ARM7)
- 16x2 LCD Display
- 4x4 Matrix Keypad
- Buzzer
- Push Buttons (Switch-1 & Switch-2)
- USB-UART Converter / DB9 Cable



 Software Requirements

- Embedded C
- Flash Magic (for code uploading)



 Working Principle

1. Setup Mode

- Press Switch-1 (EINT0) to enter configuration mode
- Options displayed on LCD:
  - Edit RTC Time
  - Set Medicine Schedule
- User enters data using keypad



2. Clock Mode

- If no medicine is set:
  - LCD displays current date and time
  - System works as a digital clock



3. Monitoring

- System continuously compares:
  RTC Time == Stored Medicine Time



4. Alert System

- When time matches:
  - LCD displays: "Take Medicine Now"
  - Buzzer turns ON (ON/OFF pattern)
  - Timer starts (1 minute)



5. Acknowledgment

- Press Switch-2 (EINT1):
  - Stops buzzer
  - Clears alert
- If not pressed:
  - Buzzer stops automatically after timeout



6. Continuous Operation

- System runs continuously
- User can reconfigure anytime

Flow of Execution

1. Initialize peripherals (RTC, LCD, keypad, buzzer, interrupts)
2. Display current time continuously
3. Detect interrupt for setup mode (EINT0)
4. Store medicine timings
5. Compare RTC with stored schedule
6. Trigger alert when matched
7. Wait for user acknowledgment (EINT1)
8. Repeat process



Key Concepts Used

- Real-Time Clock (RTC)
- External Interrupts (EINT0, EINT1)
- Embedded C Programming
- LCD Interfacing
- Keypad Scanning
- Timer/Delay Handling



Advantages

- Helps maintain proper medication schedule
- Simple and user-friendly
- Low-cost embedded solution


 Limitations

- Limited number of stored schedules
- No remote/mobile connectivity
- Manual input required


Future Enhancements

- GSM module for SMS alerts
- Mobile app integration
- IoT-based monitoring
- Voice alerts

This project is developed as part of an Embedded Systems / BTech project using LPC2148 microcontroller
