# Project Grace

Project Grace is an Unreal Engine 5 game prototype built around a modular sports and abilities-driven gameplay system. The project combines C++ gameplay code with Blueprint-driven design, aiming to support competitive sport mechanics, team-based play, AI behavior, pickups, and a flexible character framework.

## Overview

This repository contains a UE5 project focused on building a playable sports experience with:

- team-based sports gameplay and scoring systems
- character abilities and gameplayability integration
- player and ball possession logic
- AI and behavior systems
- collectible or gameplay pickups
- support for vehicles and physics-driven interactions
- a clean C++ module structure for extending gameplay systems

The project is currently structured as a game module under `Source/ProjectGrace`, with supporting content assets under `Content/` and a custom plugin setup under `Plugins/`.

## Features

### Gameplay systems
- `SportManagerComponent` for match lifecycle and score tracking
- `SportPlayerComponent` for passing, shooting, dribbling, tackling, and possession logic
- `SportBall` gameplay object for sport interactions
- `ProjectGraceBaseCharacter` base character class with ability system integration

### Ability and character framework
- Unreal Gameplay Abilities integration
- Character identity and behavior components
- Tag-based gameplay state and logic management
- Blueprint-compatible actor/component design

### Project structure
- `Source/ProjectGrace/` — main gameplay module
- `Content/` — project assets and gameplay content folders
- `Config/` — project configuration
- `Plugins/` — external or forked plugin integrations
- `ProjectGrace.uproject` — project entry point

## Tech stack

- Unreal Engine 5.7
- C++ gameplay code
- Unreal Blueprint assets
- Gameplay Abilities / Ability System
- Chaos Vehicles / Physics systems
- Editor tooling and plugin support

## Repository layout

```text
ProjectGrace/
├── Config/
├── Content/
│   ├── Blueprints/
│   ├── Character/
│   ├── Core/
│   ├── Debug/
│   ├── Gameplay/
│   ├── GameplayAbilities/
│   ├── Input/
│   └── Sport/
├── Plugins/
├── Source/
│   ├── ProjectGrace/
│   │   ├── Public/
│   │   ├── Private/
│   │   ├── ProjectGrace.Build.cs
│   │   ├── ProjectGrace.cpp
│   │   └── ProjectGrace.h
│   ├── ProjectGrace.Target.cs
│   └── ProjectGraceEditor.Target.cs
├── ProjectGrace.sln
├── ProjectGrace.uproject
├── README.md
├── COPYRIGHT.txt
└── ...
```

## Requirements

To build and run this project locally, you will need:

- Unreal Engine 5.7
- Visual Studio 2022 with C++ Desktop development tools
- Windows 10/11 (recommended for UE5 development)
- Git installed for cloning the repository

## Getting started

1. Clone the repository:

```bash
git clone https://github.com/gavinvipe/ProjectGrace.git
cd ProjectGrace
```

2. Launch the project file:

```text
ProjectGrace.uproject
```

3. If prompted, generate project files or open the project in the Unreal Editor.

4. Build the project in Visual Studio or through the UE editor.

5. Press Play to test the gameplay prototype.

## Notes for contributors

This project is a gameplay prototype and active development repository. Expect the structure and systems to evolve as the project matures.

If you are contributing:

- keep gameplay logic under the `Source/ProjectGrace` module
- prefer modular component-based systems
- maintain C++ and Blueprint compatibility where appropriate
- document major systems and gameplay flow when adding features

## License

Please see the repository's `COPYRIGHT.txt` and project licensing terms for legal details.

## Acknowledgements

This project uses Unreal Engine and integrates several gameplay and tooling systems commonly used in UE5 projects, including gameplay abilities, character systems, and plugin-based extension points.

## Status

Project Grace is a work in progress, focused on building a sport-inspired Unreal Engine gameplay foundation with a modular, extensible architecture.
