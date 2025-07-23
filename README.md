# SleepingBarberSimulation

This project implements the classic **Sleeping Barber** synchronization problem using multithreading and semaphores in C. It demonstrates concurrency control, thread management, and inter-process communication concepts within a simulated barbershop scenario.

---

<img width="1919" height="1078" alt="image" src="https://github.com/user-attachments/assets/0bd79424-9ea1-4fd0-8293-2be26bc10d33" />

<img width="1919" height="1079" alt="image" src="https://github.com/user-attachments/assets/cf29254e-0199-41be-8c4b-c1ce2ecb68b8" />

<img width="1919" height="1079" alt="image" src="https://github.com/user-attachments/assets/39c53fe9-5638-4489-9a90-9d8fcf15ecb6" />




## 🚀 How to Build & Run (WSL/Linux/Ubuntu)

### 1. Prerequisites

- **WSL** with Ubuntu (or any Linux).
- The code files from this repository.

### 2. Move to Project Directory

If your files are on Windows, copy them into your Linux home:

cp -r /mnt/c/Users/<YourWindowsUsername>/Desktop/Barber ~/
cd ~/Barber

Replace `<YourWindowsUsername>` with your actual Windows username.

### 3. Install Build Tools (First Time Only)

sudo apt update
sudo apt install build-essential


### 4. Compile

gcc barber.c -o barber -pthread


- Adjust `barber.c` to your main C source filename if necessary.

### 5. Run

./barber


- Press `Ctrl+C` to stop.

---

## 📄 Description

- Simulates a barbershop where customers arrive and wait for a barber.
- Demonstrates safe thread synchronization using semaphores and POSIX threads.

---

## 🖱️ Quick Start

cd ~/Barber
gcc barber.c -o barber -pthread
./barber


---

## 📝 Customization

Change parameters (such as number of chairs, customers, etc.) directly in `barber.c` as needed.

---

**Enjoy exploring classic concurrency with the Sleeping Barber problem!**
