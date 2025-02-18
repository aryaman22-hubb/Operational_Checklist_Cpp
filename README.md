# Operational_Checklist_Cpp

# 📝 Advanced Operational Checklist Application (C++)

A powerful and intuitive console-based Operational Checklist application built in C++ to help manage tasks effectively. This application offers features like task prioritization, deadline notifications, sorting, and recurring task management, all within a visually enhanced console UI.

---

## 🎯 Key Features

✅ **Add Tasks** with descriptions, deadlines, priorities, and recurring options  
✅ **View Tasks** in a structured list with status indicators  
✅ **Mark Tasks as Completed** with a ✅ symbol  
✅ **Sort Tasks by Deadline** (earliest first) for better organization  
✅ **Deadline Notifications** for tasks due within 2 days  
✅ **Recurring Task Management** for tasks that repeat  
✅ **Remove Completed Tasks** to keep the list clean  
✅ **Colorful Console UI** using ANSI escape codes for enhanced readability  

---

## ⚙️ Installation & Compilation

### 📌 Prerequisites  
- A **C++ Compiler** (e.g., `g++`)  
- A **Terminal that supports ANSI colors**  

### 🛠 Compilation & Execution  
To compile the application, use:  
```sh
 g++ operational_checklist.cpp -o operational_checklist -std=c++11
```
Run the application with:  
```sh
 ./operational_checklist
```

---

## 🚀 Usage Guide

### 📌 Main Menu Options

1️⃣ **Add a new task**  
```
 Enter task description: Finish project report
 Enter deadline (YYYY-MM-DD): 2025-02-20
 Enter priority (1-High, 2-Medium, 3-Low): 1
 Is this task recurring? (0-No, 1-Yes): 0
```

2️⃣ **View all tasks**  
```
 view
```

3️⃣ **Mark a task as completed**  
```
 complete [Task Number]
```

4️⃣ **Sort tasks by deadline**  
```
 sort
```

5️⃣ **Remove completed tasks**  
```
 remove_completed
```

6️⃣ **View recurring tasks**  
```
 view_recurring
```

7️⃣ **Exit the application**  
```
 exit
```

---

## 📊 Example Output

```
=============================
     📅 OPERATIONAL CHECKLIST APP      
=============================

1. ❌ Finish project report   (Deadline: 2025-02-20) | Priority: High
2. ❌ Submit assignment      (Deadline: 2025-02-19) | Priority: Medium ⚠️ Approaching!
3. ✅ Buy groceries           (Completed)

-----------------------------
Commands: add, view, complete, sort, remove_completed, view_recurring, exit
Enter a command:
```

---

## 🎨 Enhanced User Experience

- **Color-coded tasks:**  
  - ✅ **Green** for completed tasks  
  - ⚠️ **Yellow** for approaching deadlines (within 2 days)  
  - ⏳ **White** for pending tasks  
- **Sorted views:** Prioritize upcoming tasks by sorting deadlines automatically.  
- **User-friendly prompts:** Clear commands and feedback for seamless interaction.  

---

🌟 **Boost your productivity — organize, prioritize, and conquer your tasks!**  

---

## 🛠 Future Enhancements (Planned Features)

🚀 **Graphical UI** for an even better experience  
🔔 **Desktop Notifications** for upcoming deadlines  
📅 **Calendar Integration** for better task scheduling  
📱 **Mobile Version** for on-the-go task management  

---

💡 **Contribute or suggest improvements on GitHub!** 🤝

