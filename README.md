<h1 align="center">Automatic Sliding Door</h1>

## Contents
- [Overview](#Overview)
- [How it works?](#How-it-works)
- [Used technologies](#Used-technologies)

<!-- OVERVIEW -->

## Overview

Sandboxes etc. It is the control system of automatic doors used to ensure that the guest entering the playgrounds is allowed in by the cashier after paying the fee, or that the guest inside is taken out.

## How it works?

The system is controlled with a single button. If the door is closed, it opens when the button is pressed. If it is open, it turns off when the button is pressed. Pressing the button always causes the door to move in the opposite direction.

The locations where the door will stop are determined by two sensors.

<br>
<p  align="center">
    <img src="./img/kapi_SA_Sensor__baglanti.jpg" width="70%" height="70%" border: 5px solid #555 >
</p>
<div align="center"> Image: Placement and operation of the sensors. </div>
<br>


The operating status of the door is also indicated by warning lights.

Thanks to this door system, guests entering or exiting the playground can be easily controlled.

<br>
<p  align="center">
    <img src="./pcb/oto_kapi_pcb.jpg" width="80%" height="75%" border: 5px solid #555 >
</p>
<div align="center"> PCB. </div>
<br>

## Kullanılan Teknolojiler

```bash
- PIC16F628A MCU.
- Microchip XC8 compiler.
- Position sensors.
- DC motor drivers.
- Proteus PCB design.

```

## Sample working video :

<a href="https://www.youtube.com/watch?v=kIe9F6NFxtg" target="_blank">
     <img src="./img/youtube.png" alt="youtube" width="55">
</a>

- GitHub [@your-ilyas9461](https://github.com/ilyas9461)
- Linkedin [@your-linkedin](https://www.linkedin.com/in/ilyas-yağcioğlu-6a6b17217)

### *** Note : 
Since the circuit is in industrial production, PCB circuit diagrams are not shared.
