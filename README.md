# Projet de dé électronique

L'ambition de ce projet, est de vous permettre de vous initier à la conception d'une carte électronique à travers un exemple simple, que vous concevrez vous même.
Une fois que vous s'aurez dessiner et réaliser un premier circuit imprimer (PCB), vous pourrez réaliser vos propres montages électroniques.

## Description

On se propose de réaliser le dé électronique d'Heliox, qui lorsqu'on le secoue, tire un numéro de 1 à 6 de manière aléatoire.

![Dé réalisé par Heliox](Images/vue_ensemble_fonctionnel.png)

L'objectif est d'avoir un système minimaliste afin de pouvoir le faire fonctionner à partir d'une pile bouton de 3V.

Nous utiliserons donc un microcontrôleur ATtiny85 du fabricant Microchip, compatible avec les cartes Arduino ([ATtiny microcontroller comparison chart](https://en.wikipedia.org/wiki/ATtiny_microcontroller_comparison_chart)).

Voici deux sources du projet, parmi d'autres que vous retrouverez sur Internet.

1. <http://carrefour-numerique.cite-sciences.fr/wiki/doku.php?id=projets:de_electronique>

2. Le tutoriel d'Heliox est articulé en 4 épisodes :
    1. 📺 [Fabrication d'un circuit imprimé avec transfert de toner](https://youtu.be/8joLK039fjk)
    2. 📺 [Explication rapide du circuit imprimé et comment placer les composants dessus](https://youtu.be/6BOH1eVT2Hk)
    3. 📺 [Programmation du microcontrôleur ATtiny85 pour faire fonctionner le dé](https://youtu.be/S-oBujsoe-Q), [Code source HelioxLab](https://github.com/HelioxLab/electronicdice)
    4. 📺 [Création et modélisation de l'objet 3D final](https://youtu.be/o8AYCznNaCQ)

<!-- Routage du PCB réalisé par Heliox avec le logiciel  <https://fritzing.org/download/> -->
![montage du de conçu par Heliox](Images/montage_de.png)

## Evolution possible du projet

- Projet initial à partir du tutoriel d'Heliox et des composants traversants
- Même projet mais avec une carte électronique supportant des composants CMS
- Autre version avec l'utilisation de [registre à décalage](https://fr.wikipedia.org/wiki/Registre_%C3%A0_d%C3%A9calage) pour le pilotage des LED
- [Projet plus ambitieux avec des LED sur toutes les faces](https://www.youtube.com/watch?v=6NPTslF68Q0&ab_channel=maker.moekoe)

## Les outils logiciels utilisés

- CAO éléctronique KiCad en version 5.99 "[Nightly Development Builds](https://www.kicad.org/download/windows/)", est téléchargeable depuis la page du serveur, aller tout en bas pour trouver la dernière date de compilation :
<https://kicad-downloads.s3.cern.ch/index.html?prefix=windows/nightly/>
- CAO mécanique [FreeCAD](https://www.freecadweb.org/?lang=fr)
- [Arduino IDE 1.8.15](https://www.arduino.cc/en/software)
- [Visual Studio Code](https://code.visualstudio.com/)

## Le matériel du projet dé électronique (BOM)

- Matériaux PLA pour l'imprimante 3D, à partir des [fichiers STL fournis par HELIOX](https://www.thingiverse.com/thing:2798081)
- Un fer à souder pour assembler les composants sur le circuit imprimé (PCB), ainsi qu'un petit outillage, comme un multimètre, des pinces, etc...
- [Interrupteur à bascule 3 broches 1P2T, poignée haute 4 mm, SS12F15](https://fr.aliexpress.com/item/32765155281.html)
- [Piles bouton au Lithium 3V, CR2032](https://fr.aliexpress.com/item/1005001314447472.html)
- [ATtiny85](https://www.microchip.com/wwwproducts/en/ATtiny85), [Microcontrôleur MCU 8BIT 20MHZ, 8 broches DIP-8 ATTINY85](https://fr.aliexpress.com/item/32952262601.html), [ATTINY85V-10PU](https://octopart.com/attiny85v-10pu-microchip-77762335), [Farnell 1455165](https://fr.farnell.com/microchip/attiny85v-10pu/mcu-8bit-attiny-10mhz-dip-8/dp/1455165) (l'option V permet de descendre la tension d'alimentation jusqu'à 1V8)
- Interrupteur à bille (mouvement et inclinaison) : [Capteur de vibrations en métal, Boule d'inclinaison secouant commutateur, SW-520D SW520D](https://www.aliexpress.com/item/100PCS-SW-520D-SW520D-Vibration-Sensor-Metal-Ball-Tilt-Shaking-Switch/4000680935322.html)
- [Kit de LED, taille 5 mm, 2V ou 3 V, ensemble d'ampoules couleurs chaudes, blanc, rouge, bleu, vert, orange, jaune](https://fr.aliexpress.com/item/1936218827.html)
- [Assortiment de condensateurs électrolytiques, 125 Pieces 1uF 2200uF 25 Valeurs](https://www.amazon.fr/gp/product/B00JZETYIG/ref=ppx_yo_dt_b_asin_title_o01_s00)
- [Boîtier/Socket support DIP 8 broches, 0.3 inch / 7.62mm](https://www.amazon.fr/gp/product/B016S6ZQQM/ref=ppx_yo_dt_b_asin_title_o00_s00)
- [Kit résistance à fil métallique, 600 pcs/lot, 30 valeurs* 20 pcs de 10 ohms ~ 1 M ohm, 1 %, 1/4 W](https://fr.aliexpress.com/item/1005001774876666.html)
- [Support de piles, CR2032, pour piles bouton 3V](https://fr.aliexpress.com/item/32845557622.html),  modèle 3D : [20mm THT Coin Cell Holder](https://grabcad.com/library/20mm-tht-coin-cell-holder-1)

---

## TODO: Schématique

"arduino attiny85 pinout" depuis la page : https://learn.sparkfun.com/tutorials/tiny-avr-programmer-hookup-guide/attiny85-use-hints

Brochage (Pinout en Anglais) de l'ATtiny85 :

![ATtiny85 Pinout](Images/ATtiny85_Pinout_x1024.jpg)

Afin de pouvoir programmer l'ATtiny85, nous utiliserons un connecteur dit **_ISP_** ou **_ICSP_** pour In-circuit Serial Programmer, de 2x3 broches, voir [Arduino as ISP and Arduino Bootloaders](https://www.arduino.cc/en/pmwiki.php?n=Tutorial/ArduinoISP).

Nous pouvons nous inspirer du schéma d'implantation du connecteur de programmation ICSP à partir du schéma de la [carte Arduino Nano](https://store.arduino.cc/arduino-nano).

Et pour la programmation, suivre les instruction ici : [Programming ATtiny85 with Arduino Uno](https://create.arduino.cc/projecthub/arjun/programming-attiny85-with-arduino-uno-afb829)

Si vous avez tou suivit, vous aurez vu que par défaut, l'environnement Arduino IDE ne prend pas en charge les microcontrôleurs ATtiny85. Nous devons donc ajouter les cartes ATtiny à l'IDE Arduino.

Pour cela, ouvrez le menu "Fichier -> Préférences" et dans les URL du gestionnaire de cartes supplémentaires, ajoutez cette URL :

`https://raw.githubusercontent.com/damellis/attiny/ide-1.6.x-boards-manager/package_damellis_attiny_index.json`

Puis ajouter le support pour les [ATtiny](https://github.com/damellis/attiny) depuis le gestionnaire de carte.

Une fois cela effectué, vous pourrez choisir le type de carte ATtiny25/45/85, préciser bien le modèle du "processeur" ATtiny85 et le choix de l'horloge interne à 8 MHz.

TODO: passer à 1 MHz et voir la différence de consommation...

---

### de_elec.kicad_sch

Nous allons étudier ensemble le montage électronique ;-)

Le microcontrôleur ATtiny85 dispose de 8 broches, dont 2 sont réservées pour son alimentation électrique.

Nous devons donc sélectionner les broches numériques d'entrées/sorties (E/S) permettant le bon fonctionnement de notre projet.

Tout d'abord, nous aurons besoin d'une entrée pour le capteur de mouvement à bille.
Il faut alors ce pencher sur les fonctions des broches du microcontrôleur afin de pouvoir décider quelle broche nous sera utile afin de pouvoir détecter cet évènement.

Mettre les LED sous la forme du dé avec une numérotation Ligne/Colonne (L/C) :

|   L/C  |  C1  |  C2  |  C3  |
|:------:|:----:|:----:|:----:|
| **L1** | L1C1 | L1C2 | L1C3 |
| **L2** | L2C1 | L2C2 | L2C3 |
| **L3** | L3C1 | L3C2 | L3C3 |

- Chiffre 1 : (L2C2)
- Chiffre 2 : (L3C1 + L1C3)
- Chiffre 3 : (L3C1 + L1C3) + (L2C2)
- Chiffre 4 : (L3C1 + L1C3) + (L1C1 + L3C3)
- Chiffre 5 : (L3C1 + L1C3) + (L1C1 + L3C3) + (L2C2)
- Chiffre 6 : (L3C1 + L1C3) + (L1C1 + L3C3) + (L2C1 + L2C3)

En regroupant les LED entre parenthèse, nous voyant que nous devons piloter séparément les groupes suivant, si l'on veux pouvoir afficher tous les chiffres :

- 1 broche en sortie pour commander la LED L2C2, nous la nommerons CMD_L2C2
- 1 broche en sortie pour commander les LED L3C1 et L1C3, nous la nommerons CMD_L3C1L1C3
- 1 broche en sortie pour commander les LED L1C1 et L3C3, nous la nommerons CMD_L1C1L3C3
- 1 broche en sortie pour commander les LED L2C1 et L2C3, nous la nommerons CMD_L2C1C3

Soit un total de 4 broches en sorties pour la commande des LED du projet :

![Pilotage des LED](Images/de_sequence_chiffre_1_a_6.gif)

---

## Internet ⚀, ⚁, ⚂, ⚃, ⚄, ⚅

- [Dé — Wikipédia](https://fr.wikipedia.org/wiki/D%C3%A9)
- [Lancez un dé virtuel!](https://de.virtuworld.net/)
- [Patrons de dés à jouer](https://www.fiche-maternelle.com/fabriquer-son-des-a-jouer.html)
- [Heliox - Fabriquer un circuit imprimé - EP01 Projet Dé Electronique](https://www.youtube.com/watch?v=8joLK039fjk&ab_channel=Heliox), voir "[EP02 Projet Dé Electronique](https://www.youtube.com/watch?v=6BOH1eVT2Hk&ab_channel=Heliox)"
- [dé électronique qui se déclenche par passage de la main au dessus d'une photorésistance](https://sciences-du-numerique.fr/projet-arduino-pour-la-specialite-isn/de-electronique/41)
- [Fabriquer soit même un Dé électronique sans Arduino](https://www.youtube.com/watch?v=spbdDq6kvxw&ab_channel=ElectroMic)

---

## License

[![MIT License](http://rasterweb.net/raster/wp-content/uploads/2011/05/opensource2.png?raw=true "Projet Open Hardware et Open Source by Artilect")](https://opensource.org/licenses/MIT)

[Open Hardware](https://fr.wikipedia.org/wiki/Mat%C3%A9riel_libre)

[MIT License](https://opensource.org/licenses/MIT)
