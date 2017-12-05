# SynthProject

This FM-synthesizer is project made for Sovellettu signaalinkäsittely course.

To get the application work, some prodecures are needed to do.

1. Download sqlite 
2. Link sqlite libraries to IDE
* XCode: Click SynthProject->General->Linked Frameworks and Libraries
            -> add libsqlite3.tbd or equivalent
3. Projucer tends to sometimes to override some constructors, because the UI designer is used
 -> go to GUI.cpp and GUI.h and modify constructors with constructors that are commented near the 
    contructor
4. Now the app should be ready to build
