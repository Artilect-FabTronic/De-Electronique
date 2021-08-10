# Projet de dé électronique

On se propose de réaliser le dé électronique qui, lorsque l'on le secoue, tire un numéro au hasard.

Nous utiliserons un microcontrôleur ATtiny85 de Microchip compatible avec les carte Arduino.

Voici une source du projet (parmi d'autres sur Internet): http://carrefour-numerique.cite-sciences.fr/wiki/doku.php?id=projets:de_electronique

[Arduino as ISP and Arduino Bootloaders](https://www.arduino.cc/en/pmwiki.php?n=Tutorial/ArduinoISP)

Implantation du connecteur de programmation ICSP à partir du schéma de la carte Arduino Nano :

https://store.arduino.cc/arduino-nano

Depuis : "L'impression 3D pour les projets électroniques - EP04 Projet Dé Electronique" (18 févr. 2018)
https://www.youtube.com/watch?v=o8AYCznNaCQ&ab_channel=Heliox
Et "Programmer un attiny85 - EP03 Projet Dé Electronique"https://www.youtube.com/watch?v=S-oBujsoe-Q&ab_channel=Heliox
https://www.microchip.com/wwwproducts/en/ATtiny85

## TODO: Schématique

### de_elec.kicad_sch

Mettre les LED sous la forme du Dé avec une numérotation ligne/colonne

| L1C1 | L1C2 | L1C3 |
| L2C1 | L2C2 | L2C3 |
| L3C1 | L3C2 | L3C3 |

## TODO: Recherche composants pour d'autres versions du dé

Série vers série Parallèle HC , Unidirectionnel 8 bit SOIC 16 broches
https://fr.rs-online.com/web/p/compteurs-et-registres-a-decalage/1713136 ***
Code commande RS: [436-7638](https://fr.rs-online.com/web/p/compteurs-et-registres-a-decalage/4367638)
Référence fabricant: 74HC595D,112
Marque: Nexperia
74HC595D SO16 plastic small outline package; 16 leads; body width 3.9 mm
Package Version: SOT109-1

https://fr.rs-online.com/web/c/afficheurs-et-optoelectronique/led-et-accessoires/led/?&applied-dimensions=4294080478,4294458855

LED Vert, Rouge, CMS, PLCC 4, 2 LEDs, 2,5 V
https://fr.rs-online.com/web/p/led/8721727

## Internet ⚀, ⚁, ⚂, ⚃, ⚄, ⚅

- [Dé — Wikipédia](https://fr.wikipedia.org/wiki/D%C3%A9)
- [Lancez un dé virtuel!](https://de.virtuworld.net/)
- [Patrons de dés à jouer](https://www.fiche-maternelle.com/fabriquer-son-des-a-jouer.html)
- [Heliox - Fabriquer un circuit imprimé - EP01 Projet Dé Electronique](https://www.youtube.com/watch?v=8joLK039fjk&ab_channel=Heliox), voir "[EP02 Projet Dé Electronique](https://www.youtube.com/watch?v=6BOH1eVT2Hk&ab_channel=Heliox)"
- [dé électronique qui se déclenche par passage de la main au dessus d'une photorésistance](https://sciences-du-numerique.fr/projet-arduino-pour-la-specialite-isn/de-electronique/41)
- [Fabriquer soit même un Dé électronique sans Arduino](https://www.youtube.com/watch?v=spbdDq6kvxw&ab_channel=ElectroMic)
- [Le registre à décalage](https://www.fabriqueurs.com/le-registre-a-decalage-sipo/)
