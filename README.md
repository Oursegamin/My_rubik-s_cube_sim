# Rubik's Cube Simulator

Ce projet est un simulateur de Rubik's Cube en 3D. Il permet de faire tourner le Rubik's Cube virtuellement en utilisant la souris pour interagir avec l'objet. Le simulateur applique des rotations sur le cube en fonction des mouvements de la souris, créant ainsi une expérience interactive et réaliste.

---

## Fonctionnalités

- **Simulation 3D du Rubik's Cube** : Le cube est modélisé en 3D avec des couleurs réalistes pour chaque face du cube.
- **Interaction avec la souris** : La rotation du cube se fait en déplaçant la souris sur l'écran. Les déplacements verticaux et horizontaux ajustent respectivement les angles de rotation sur les axes X et Y.
- **Rotation dynamique** : Les rotations sont appliquées en temps réel, et le cube répond instantanément aux mouvements de la souris.
- **Interface simple et intuitive** : L'interface est simple à utiliser, sans contrôles compliqués. Il suffit de glisser la souris pour faire tourner le cube.

---

## Prérequis

Avant de commencer, assurez-vous d'avoir les outils suivants installés sur votre machine :

- **C++ compiler** : Un compilateur C++ compatible (comme `g++` ou `clang++`).
- **SFML** : Bibliothèque pour la gestion des fenêtres et de l'affichage graphique.
- **OpenGL** : Utilisé pour le rendu 3D du Rubik's Cube.

---

### Installation sur Windows

## Compilation et exécution sous Windows

### Prérequis

1. **MinGW** : Assurez-vous que MinGW est installé et configuré sur votre machine.
   - Ajoutez `mingw32/bin` à votre variable d'environnement `PATH`.

2. **SFML** :
   - Téléchargez SFML depuis [le site officiel](https://www.sfml-dev.org/download.php).
   - Extrayez les fichiers et placez-les dans un répertoire (par exemple `C:/SFML`).
   - Configurez les chemins des bibliothèques et des en-têtes :
     - `C:/SFML/lib` pour les fichiers `.lib`.
     - `C:/SFML/include` pour les fichiers `.hpp`.

### Commandes de compilation et d'exécution

1. **Compilation**

   - Pour compiler le projet pour Windows, utilisez la commande suivante : 

        ```bash
        make build_windows
        ```

    - Cela génère un exécutable rubiks_cube.exe dans le répertoire courant.

2. **Exécution**

   - Une fois compilé, vous pouvez exécuter le programme avec la commande suivante :
        ```bash
        make run_windows
        ```
---

### Installation sur Fedora

1. Installez les dépendances nécessaires :

```bash
sudo dnf install sfml-devel
sudo dnf install mesa-libGL-devel
```

2. Clonez le projet depuis le dépôt Git (si applicable)

```bash
git clone git@github.com:Oursegamin/My_rubik-s_cube_sim.git
cd My_rubik-s_cube_sim
```

3. Compilez le projet :

```bash
make [re] [-s]
```

4. Lancez l'application :

```bash
./rubiks_cube
```

---

### Utilisation

- **Contrôles de la souris** : Faites glisser la souris pour faire tourner le cube dans toutes les directions. Le mouvement vertical (haut/bas) contrôle la rotation autour de l'axe X, et le mouvement horizontal (gauche/droite) contrôle la rotation autour de l'axe Y.

- **Rotation** : Chaque mouvement de souris sur l'écran déclenche une mise à jour des rotations appliquées sur le cube. La rotation sera fluide et correspondra aux déplacements de la souris en temps réel.

---

### Developpement

#### Structure du projet

- **main.cpp** : Le fichier principal contenant le cœur de l'application. Ce fichier gère l'affichage et la logique de la simulation.

- **RubiksCube.cpp** / RubiksCube.hpp : Les fichiers qui contiennent la logique pour gérer les rotations et les interactions avec le cube.

- **Matrix4.hpp** / Matrix4.cpp : Gère les matrices 4x4 pour les transformations et les rotations du cube en 3D.

- **Shader** :Si vous utilisez des shaders pour améliorer le rendu, assurez-vous que les fichiers sont bien chargés et utilisés dans votre application.

---

#### Améliorations possibles

- **Ajout de la gestion des couleurs dynamiques** : Actuellement, les couleurs du cube sont statiques. Il est possible de rendre le Rubik's Cube interactif en permettant aux utilisateurs de changer les couleurs des faces.

- **Ajout d'un mode de résolution automatique** : Implémenter un algorithme qui résout le Rubik's Cube de manière automatique.

- **Interface utilisateur améliorée** : Ajouter des boutons et des contrôles pour réinitialiser la position du cube ou pour réinitialiser l'état du simulateur.

---

### Contributeurs

- **Axel Lavrador ([GitHub](https://github.com/Oursegamin))**

