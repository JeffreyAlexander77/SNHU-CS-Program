# The Gaming Room - Software Design Reflection

## Project Summary
The client for this project was The Gaming Room, who requested a transition of their existing Android-only game application, "Draw It or Lose It", into a modern, web-based platform. The software functions as a multiplayer team competition inspired by classic drawing games. Technologically, the application requires robust cross-platform accessibility, a client-server architecture, secure user authentication, data persistence via REST APIs, and strict design constraints—such as ensuring unique game/team identifiers and enforcing that only a single instance of a game service exists in memory at any given time using the Singleton design pattern.

## Reflection Questions

### 1. What did you do particularly well in developing this documentation?
I believe I excelled at structuring the architectural overview and clearly outlining the domain model for the application. I was able to successfully translate the abstract business requirements of managing unique games, teams, and players into explicit software constraints, ensuring the layout was clean and highly professional.

### 2. What about the process of working through a design document did you find helpful when developing the code?
Working through the design document prior to diving into the codebase was invaluable because it provided an unambiguous structural blueprint. Mapping out the patterns—specifically the Singleton pattern for the game service infrastructure—prevented critical memory allocation and logic errors during implementation, as I already knew exactly how objects should co-exist.

### 3. If you could choose one part of your work on these documents to revise, what would you pick? How would you improve it?
If I could revise one aspect of my work, I would expand upon the operating system evaluation matrices. I would provide a deeper technical dive into the specific latency, storage capabilities, and data transfer trade-offs between hosting the backend services on different traditional operating system environments.

### 4. How did you interpret the user's needs and implement them into your software design? Why is it so important to consider the user's needs when designing?
I interpreted the user's needs by focusing heavily on seamless cross-platform delivery and low overhead requirements. Because players access the game from multiple operating systems, the software design prioritized web-based services over device-specific compiled code. Considering user needs during the initial design phase is absolutely critical to avoid bloated architectures, fragmented user interfaces, and high operational costs.

### 5. How did you approach designing software? What techniques or strategies would you use in the future to analyze and design a similar software application?
My approach to designing software centered on modularity, decoupling, and standard design patterns. By breaking the requirements down into distinct functional units (such as user authentication, game instance management, and team tracking), the complexity became highly manageable. In future projects, I will continue to leverage robust strategies like UML domain modeling and formal software design documents to ensure a scalable production cycle.
