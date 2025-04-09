// Project: Smart Voice Reminder using ESP32 (Serial input only)
// Output: Serial Monitor Only
// Author: Aman (solitarybear)

String inputCommand = "";
unsigned long reminderTime = 0;
unsigned long triggerTime = 0;
bool reminderSet = false;

void setup() {
  Serial.begin(115200);
  Serial.println("✅ Smart Voice Reminder Ready");
  Serial.println("Type: Remind me in <time in seconds> to <task>");
}

void loop() {
  // Check for incoming Serial input
  if (Serial.available()) {
    inputCommand = Serial.readStringUntil('\n');
    inputCommand.trim();
    parseReminder(inputCommand);
  }

  // Check if reminder should trigger
  if (reminderSet && millis() >= triggerTime) {
    Serial.println("🔔 Reminder: " + inputCommand);
    reminderSet = false;
  }
}

void parseReminder(String command) {
  if (command.startsWith("Remind me in")) {
    int timeStart = command.indexOf("in") + 3;
    int timeEnd = command.indexOf("to");

    if (timeEnd == -1) {
      Serial.println("⚠️ Invalid format. Use: Remind me in <time in sec> to <task>");
      return;
    }

    String timePart = command.substring(timeStart, timeEnd);
    String task = command.substring(timeEnd + 3);
    timePart.trim();
    task.trim();

    int seconds = timePart.toInt();

    if (seconds <= 0 || task == "") {
      Serial.println("⚠️ Please specify a valid time and task.");
      return;
    }

    reminderTime = seconds * 1000UL;
    triggerTime = millis() + reminderTime;
    inputCommand = task;
    reminderSet = true;

    Serial.println("✅ Reminder set in " + String(seconds) + " seconds to: " + task);
  } else {
    Serial.println("⚠️ Unrecognized command.");
  }
}
