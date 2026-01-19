# MobileGas – Gas Safety Monitor (ESP32‑S3)

MobileGas is a modular, maintainable gas‑detection system built on the ESP32‑S3.  
It features a multi‑sensor array, SH1106 OLED display, diagnostic overlays, active buzzer and status LEDs, a clean UI abstraction layer, and a web interface for remote monitoring.

---

## 📄 Documentation

All documentation lives in the `/docs` folder.

### Core Specification
- [Functional Specification Document (FSD)](docs/mobilegas.fsd.md)

### Architecture
- [System Overview](docs/architecture/system-overview.md)
- [Module Diagram](docs/architecture/module-diagram.md)
- [Data Flow](docs/architecture/data-flow.md)

### User Interface
- [Display Layouts](docs/ui/display-layouts.md)
- [Diagnostic Overlays](docs/ui/diagnostic-overlays.md)
- [Boot Screen](docs/ui/boot-screen.md)

### Sensors
- [MQ2](docs/sensors/mq2.md)
- [MQ135](docs/sensors/mq135.md)
- [SGP30](docs/sensors/sgp30.md)
- [BME280](docs/sensors/bme280.md)

### Firmware
- [Build Instructions](docs/firmware/build-instructions.md)
- [Error Handling](docs/firmware/error-handling.md)
- [Testing Checklist](docs/firmware/testing-checklist.md)

---

## 🧩 Hardware Components

- **Active Buzzer:** GPIO 11 (PWM capable) for audible alarms  
- **Status LEDs:**  
  - Green LED → GPIO 12 (normal operation)  
  - Yellow LED → GPIO 13 (warnings)  
  - Red LED → GPIO 14 (alarms)  

---

## 🌐 Web Interface

MobileGas includes a web interface for remote monitoring and configuration:  
- Real-time sensor data dashboard  
- Configuration panels for alarm thresholds and system settings  
- Visual indicators matching device LEDs  
- Responsive design for desktop and mobile browsers  
- Secure access with authentication  

---

## 🧩 Project Structure

---

## 🚀 Goals

- Modular display subsystem  
- Clear UI abstraction layers  
- Reliable sensor acquisition  
- Robust diagnostics and boot‑time indicators  
- Maintainable, future‑proof architecture  
- Integrated buzzer and LED alarm indicators  
- Remote monitoring and configuration via web interface  
