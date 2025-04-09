# 🗣️ Smart Voice Reminder using ESP32

A basic reminder system where you can type natural voice-like commands into the Serial Monitor (e.g., “Remind me in 30 seconds to check food”), and the ESP32 will alert you after the specified time. It’s a lightweight demonstration of how IoT devices can understand voice-style instructions and act like personal assistants.

---

## 🧠 Idea

We often forget small tasks while working or cooking. This project lets users “talk” to the ESP32 using typed commands like:

Remind me in 60 to turn off stove

And after 60 seconds, the ESP32 responds via Serial Monitor with a reminder.

---

## ⚙️ How It Works

- Input is given through Serial Monitor in a voice-like format
- ESP32 parses time and task from the sentence
- Sets a countdown timer
- Sends a reminder when the timer expires

Example input:

Remind me in 45 to call mom


Output after 45 seconds:

🔔 Reminder: call mom


---

## 📦 Components Used

- ESP32 Dev Module
- USB Cable (for Serial communication)
- Computer with Arduino IDE


---

## 📈 Future Enhancements

- Integrate voice recognition module (like Elechouse V3)
- Add speaker or buzzer output
- Store multiple reminders using RTC and EEPROM
- App or web-based front-end

---

## 👤 Author

Made with ❤️ by [@solitarybear](https://github.com/solitarybear)
