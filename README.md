📌 Customer Queue Management System – C++ Console Application
🔹 Description:
A simple and effective console application that simulates a customer service queue system. The project demonstrates how to issue service tickets, track served and waiting clients, and manage the queue efficiently using C++ Standard Library features.

🚀 Features:
Issue tickets with unique prefixes and numbers.

Track served and waiting clients.

View the next client to be served.

Display ticket info in both LTR (left-to-right) and RTL (right-to-left) formats.

Estimate service time per client.

Fully console-based with clear and simple UI.

Clean Code with OOP principles (clsTicket, clsQueueLine).

No external libraries used.

🛠️ Technologies Used:
C++

Console Application

Standard Library (<queue>, <stack>, <string>, <iostream>)

📦 Project Structure:
clsQueueLine: Main class managing ticket issuing and client serving.

clsTicket: Inner class holding individual ticket info (time, number, prefix, etc).

clsDate: Used to fetch system time string (you can replace or implement your own).

📸 Preview:
(You can add screenshots or console output samples here if you'd like.)

📂 How to Run:
Open the project in any C++ IDE (e.g., Visual Studio).

Make sure clsDate is implemented or mock it with a simple system time function.

Compile and run the project.

Use the console to test ticket issuing and queue management.

💡 Example Use Case:
cpp
Copy
Edit
clsQueueLine MyLine("A", 3); // Prefix "A", service time = 3 minutes per client

MyLine.IssueTicket();
MyLine.IssueTicket();
cout << MyLine.WhoIsTheCurrentClient(); // Shows first client in queue
MyLine.ServeTheNextClient();            // Moves to next client
📎 Notes:
Project is modular and easy to expand.

Useful as a base for more advanced systems (e.g., bank queue, clinic system).

Educational tool to practice data structures and OOP in C++.

📢 Author:
Ahmed Elhwwary
🔗 Telegram channel for more projects: @ahmedelhwwary3

