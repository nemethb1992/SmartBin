# Intelligens érintésmentes szemetes telítettségfigyeléssel

## Digitális Technika II. projekt

---

## Projekt bemutatása

Az automatizált rendszerek egyre nagyobb szerepet kapnak a mindennapi életben. Az érintésmentes eszközök higiénikusabb használatot tesznek lehetővé, ezért jelen projekt célja egy **Arduino alapú intelligens szemetes** megvalósítása.

A rendszer:

- ultrahangos szenzor segítségével érzékeli a felhasználó kezét,
- automatikusan nyitja a fedelet szervomotor segítségével,
- automatikusan visszazárja a fedelet,
- figyeli a szemetes telítettségét,
- LED-es visszajelzést ad telítettség esetén.

SmartBin_Components.png
---

## Projekt célja

A projekt célja egy olyan rendszer létrehozása, amely:

- automatikusan nyitja a szemetes fedelét  
- automatikusan visszazárja azt  
- érzékeli a telítettséget  
- LED-es figyelmeztetést ad  
- csökkenti a fizikai érintkezést  

---

## Felhasznált alkatrészek

| Alkatrész | Mennyiség |
|----------|------------|
| Arduino Uno | 1 |
| HC-SR04 ultrahangos szenzor | 2 |
| SG90 szervó motor | 1 |
| Piros LED | 1 |
| Zöld LED | 1 |
| 220Ω ellenállás | 2 |
| Breadboard | 1 |
| Jumper kábelek | Több |

---

## Működési elv

A rendszer működése:

1. A felhasználó keze a szenzor közelébe kerül
2. Az ultrahangos érzékelő érzékeli a közelséget
3. A szervómotor kinyitja a fedelet
4. A zöld LED jelzi a nyitott állapotot
5. Néhány másodperc után a fedél bezár
6. A második szenzor figyeli a telítettséget
7. Ha megtelt:
   - a piros LED villog
   - figyelmeztetés jelenik meg

---

## Állapotdiagram

### Normál működés

```text
START
 ↓
Kéz érzékelve?
 ↓
IGEN
 ↓
Fedél nyit
 ↓
3 mp várakozás
 ↓
Fedél zár
```

### Telítettségfigyelés

```text
Szemetes tele?
 ↓
IGEN
 ↓
Piros LED villog
 ↓
Figyelmeztetés
```

---

## Kapcsolási rajz

Ide kerül a Tinkercad kapcsolási rajz képernyőképe:



*(A képfájlt majd töltsd fel a repository-ba.)*

---

## Bekötések

## HC-SR04 #1 (kéz érzékelés)

| Szenzor | Arduino |
|---------|----------|
| VCC | 5V |
| GND | GND |
| TRIG | D9 |
| ECHO | D10 |

---

## HC-SR04 #2 (telítettség)

| Szenzor | Arduino |
|---------|----------|
| VCC | 5V |
| GND | GND |
| TRIG | D7 |
| ECHO | D8 |

---

## Szervó

| Szervó | Arduino |
|--------|----------|
| VCC | 5V |
| GND | GND |
| Signal | D6 |

---

## LED-ek

| LED | Arduino |
|-----|----------|
| Piros LED | D2 |
| Zöld LED | D3 |

---

## Program felépítése

A program fő funkciói:

- Távolságmérés
- Szervóvezérlés
- LED állapotkezelés
- Telítettség figyelése
- Automatikus nyitás/zárás

---

## Távolságmérés

```cpp
float measureDistance(int trigPin, int echoPin)
```

Feladata:

- ultrahangos szenzor indítása
- visszaverődési idő mérése
- távolság számítása

---

## Szervó vezérlése

Nyitás:

```cpp
lidServo.write(90);
```

Zárás:

```cpp
lidServo.write(0);
```

---

## Telítettségfigyelés

Ha a szemetes megtelt:

```cpp
if(fillDistance < 15){

    full = true;

    Serial.println("SZEMETES TELE!");

    // piros LED villog
    digitalWrite(
        redLED,
        (millis()/300)%2
    );

}
else{

    full = false;
}
```

A piros LED villogással figyelmeztet.

---


# Továbbfejlesztési lehetőségek

A projekt tovább bővíthető:

- LCD kijelző
- hangjelzés (buzzer)
- mobil értesítés
- WiFi kapcsolat
- IoT integráció
- telítettség százalékos kijelzés

---

# Összegzés

A projekt során sikerült egy Arduino alapú intelligens szemetes prototípust létrehozni, amely automatikus nyitást és telítettségfigyelést valósít meg.

A rendszer bemutatja:

- ultrahangos szenzorok használatát,
- szervómotor vezérlését,
- LED visszacsatolást,
- automatizált állapotkezelést.
