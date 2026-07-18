# 💊 USER-CONFIGURABLE MEDICINE REMINDER SYSTEM

## ⭐ Overview
A smart User-Configurable Medicine Reminder System developed using the LPC2148 ARM7 Microcontroller to help users take medicines at the correct scheduled time.

Unlike conventional fixed alarm systems, this project allows the user to configure medicine timings dynamically using a 4x4 Matrix Keypad.

The system continuously monitors the Real-Time Clock (RTC) and compares the current time with stored medicine schedules.

When the scheduled medicine time occurs, the system:

💊 Displays "Take Medicine Now"

🔔 Activates the Buzzer

⏱ Starts an Acknowledgment Timer

🔘 Waits for User Confirmation

🔄 Automatically returns to RTC Monitoring

## 🎯 Project Objectives
Display Real-Time Clock on LCD

Allow User-Configurable Medicine Timings

Monitor Medicine Schedules in Real Time

Generate Automatic Medicine Alerts

Provide Buzzer-Based Reminder

Support User Acknowledgment

Automatically Stop Alert After Timeout

Allow RTC Date and Time Modification

Implement External Interrupt-Based Control

Provide Continuous Medicine Schedule Monitoring

## 📷 Complete System Architecture

<img width="1222" height="816" alt="17843512094508669100370883134906" src="https://github.com/user-attachments/assets/60977e55-2023-4730-bf28-8603e4664905" />

## ⚙️ SYSTEM WORKING

The user configures the required medicine reminder schedule using the available input interface.

The LPC2148 microcontroller receives and processes the user-defined settings.

The configured reminder information and system status are displayed on the LCD.

The system continuously monitors the medicine schedule and compares it with the current timing information.

When the configured medicine time is reached, the system generates an alert to notify the user.

After the reminder is acknowledged, the system continues monitoring for the next configured medicine schedule.

## 🔄 PROJECT WORKFLOW


<img width="1535" height="1024" alt="1784353526393156905651548276775" src="https://github.com/user-attachments/assets/ccbb9d9c-ceb3-45c1-bd75-90f27c43df91" />

## ✨ KEY FEATURES

- ⏰ User-configurable medicine reminders
- 💊 Automated medicine schedule monitoring
- 🖥️ Real-time information display
- 🔔 Automatic alert generation
- 🎛️ Simple user interaction
- ⚡ ARM7-based embedded implementation
- 💻 Embedded C firmware development
- 🔄 Continuous reminder monitoring
- 🏥 Healthcare-oriented embedded application

  ## 🧩 HARDWARE COMPONENTS

| Component | Purpose |
|---|---|
| **LPC2148 ARM7** | Main system controller |
| **LCD Display** | Displays reminder information and system status |
| **Matrix Keypad** | User input and reminder configuration |
| **Buzzer** | Generates medicine reminder alerts |
| **Push Buttons** | User control and acknowledgement |
| **Power Supply** | Provides power to the embedded system |

## 💻 SOFTWARE & DEVELOPMENT TOOLS

| Tool | Purpose |
|---|---|
| **Embedded C** | Firmware development |
| **Keil µVision** | Code development and compilation |
| **Flash Magic** | Programming the LPC2148 microcontroller |

## 🚀 APPLICATIONS

- Personal Medicine Reminder Systems
- Elderly Healthcare Assistance
- Home Healthcare Systems
- Medication Management Systems
- Patient Care Applications
- Smart Healthcare Devices


## 👩‍💻 AUTHOR

### Rohini

**Bachelor of Technology (B.Tech)**  
**Electronics & Communication Engineering**

🎯 **Embedded Systems | Embedded Firmware**


## 📜 LICENSE

This project is developed for **educational and academic purposes**.

The project can be used for learning, modification, and further development for non-commercial purposes.



# 🙏 THANK YOU
