# 🖥️ Cyber Breach

> A terminal-based hacking-themed game developed in C++.

## ⚠️ Important

Cyber Breach is a **fictional game**. The attacks, systems, and cybersecurity elements featured in the game are used purely as gameplay mechanics.

---

# 🎮 About the Game

In **Cyber Breach**, you play as a hacker trying to defeat different security systems.

You can:

- ⚔️ Fight security systems
- 💻 Use different attacks
- 🧠 Gain experience
- 📈 Level up
- 🪙 Earn CryptoCoins
- 🛒 Buy upgrades
- 🛡️ Upgrade your Firewall
- ❤️ Restore your system
- 🔥 Attempt critical attacks

---

# 🚀 Installation

## 🐧 Linux

### 1. Install the C++ compiler

On Debian / Ubuntu:

```bash
sudo apt update
sudo apt install build-essential make
```

On Arch Linux:

```bash
sudo pacman -S base-devel
```

On Fedora:

```bash
sudo dnf install gcc-c++ make
```

---

### 2. Get the project

If you have Git installed:

```bash
git clone https://github.com/Kaezuria/Cyber-Breach.git
cd Cyber-Breach
```

Or simply download the project files and place them inside a folder.

---

### 3. Compile the game

```bash
make
```

---

### 4. Run the game

```bash
make run
```

Or directly:

```bash
./cyberbreach
```

---

# ⚡ Quick Installation

To compile and install the game system-wide:

```bash
make
sudo make install
```

After installation, you can launch Cyber Breach from any terminal:

```bash
cyberbreach
```

---

# 🗑️ Uninstallation

To remove the game from your system:

```bash
make uninstall
```

---

# 🛠️ Make Commands

| Command | Description |
|---|---|
| `make` | Compile the game |
| `make run` | Compile and run the game |
| `make install` | Install the game system-wide |
| `make uninstall` | Uninstall the game |
| `make clean` | Remove compiled files |
| `make rebuild` | Completely rebuild the game |
| `make help` | Display all available commands |

---

# 🎮 Gameplay

## ⚔️ Battles

When launching an attack, you can encounter different security systems:

- Basic Firewall
- Sentinel Antivirus
- IDS System
- Security Agent
- AI Defender

You have several attacks available.

### 💉 SQL Injection

A basic attack that deals damage to the system.

### 🌊 DDoS

A more powerful attack.

### 💥 Zero-Day Exploit

A risky attack with a chance to land a powerful critical hit.

### 🏃 Escape

You can try to escape from a battle.

But be careful — your IP might get traced 👀

---

# 🛒 Dark Web Shop

After winning battles, you earn **CryptoCoins**.

You can use them to:

- ❤️ Restore your HP
- ⚔️ Increase your attack power
- 🛡️ Upgrade your Firewall

---

# 📈 Progression

By winning battles, you earn experience points.

Once you have enough XP:

```text
LEVEL UP!
```

Your character becomes stronger:

- +20 maximum HP
- +5 attack power
- Full HP restoration

---

# 📁 Project Structure

```text
Cyber-Breach/
│
├── main.cpp
├── Makefile
└── README.md
```

---

# 🧑‍💻 Manual Compilation

If you don't want to use `make`:

```bash
g++ -std=c++17 -Wall -Wextra -O2 main.cpp -o cyberbreach
```

Then run:

```bash
./cyberbreach
```

---

# 🪟 Windows

Using MinGW:

```bash
g++ -std=c++17 -Wall -Wextra -O2 main.cpp -o cyberbreach.exe
```

Then run:

```bash
cyberbreach.exe
```

---

# 🔮 Planned Features

- [ ] Save system
- [ ] Multiple bosses
- [ ] Final boss
- [ ] Mission system
- [ ] Inventory
- [ ] Skill tree
- [ ] Player leaderboard
- [ ] Hardcore mode
- [ ] More enemies
- [ ] Graphical interface
- [ ] Music and sound effects

---

# 🛡️ Disclaimer

This project is a fictional and educational game created for programming practice and entertainment.

Any cybersecurity-related elements are fictional gameplay mechanics and are not intended as instructions for attacking real-world systems.

---

<div align="center">

## Cyber Breach // Terminal Game

`keep learning. keep coding. stay curious.`

Made with ❤️ and C++

</div>
