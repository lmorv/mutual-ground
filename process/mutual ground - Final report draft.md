
### Abstract

### Design Narrative & Prototype process
Our intention was to create a conversation type interaction that simulates the process of initial discomfort to discovery of social interaction trough an abstracted means of communication. 
To this end we set out to construct a kinetic sculpture out of wire that would move and respond according to user input. 

The choice of material allowed us to narrow down our focus and technique, and encouraged us to develop the material skills to craft wire structures. Our initial attempts were not very structurally sound.

For our second iteration of the device we used a thicker grade of wire, which helped a lot with stability and the integrity of joints and movable parts. The main axis of motion was much more reliable as a functional crank. However the reduced malleability of the wire also brough more challenges, bending it to very specific shapes, in tight arches, or around the base to fix it in place or 'tie' new pieces to the structure required pliers and considerable force. 

As more embellishment was added, and also the attachment for the motor, the shape and relative positioning of the moving poles became very important to the functioning of the device. A slight misalignment, a part colliding with another and getting caught, or friction resulting from increased tension at a given section would cause the motor to stop.

We took to working with the motor connected to power for continuous periods of time as we made adjustments to the structure, testing and modifying its shape, reenforcing the motor base and, sometimes cutting wires that had tightened to much, and adding new decorative embellishment.  

At some point it became necessary to remove some of the movable poles attached to the main crank axis in order to reduce the friction and simplify the debugging process, we ended up with 3 out of the 5 original 'whiskers'.

We took care to bend back the sharp points resulting from cuts in the wire.

In terms of circuitry we spent some time developing, the capacitor sensors, using a specialized Arduino library and experimenting with detecting value ranges. The results were often unpredictable and we got the best results with a series of 3 100k ohm resistors wired in series and with the computer (acting as power source for the Arduino) was connected to an electrical socket.

The development of the motor code went through two major iterations, at first we though it would be necessary to use a rotary encoder and a [weird component] a bridge(?) and an occilator (?) regulator(?) to manipulate the speed. This thread of experimentation did not work out, we could not get the proposed circuit to run.

Instead we used a MOSFET transistor to modify the voltage coming in to the motor from a secondary power source trough code. The motor needed a minimum of 9 volts of reliable power in order to move, and its lowest speed was still really much faster than we expected, this gave us a very subtly changing range of speeds to work with in the final implementation.

### Final Artefact

The final artefact is a dense cloud of wire tangle, the movement produced by the motor too fast and violent, the curves on the bracelets and the spherical shape of the kinetic sculpture range from almost graceful to chaotic. It is perfect in every way to us.

The interaction loop is such that the kinetic sculpture must be touched in order to begin it's functioning, and then turn on-and off at slightly different speed according to configurations of contact made with the components of the piece (the capacitance-enabled bracelets and the kinetic sculpture). This is achieved trough code by the definition of states according to capacitance value for each component, these states are then grouped into configurations of states that add an extra layer of unpredictability to the outcome. An initial 'if' statement surrounding these second order state-configuration conditions enables the initial 'touch to activate' feature of the system.

### Observations
The unpredictable nature of the state configurations, along with the violent nature of the artefact's movement, made it so that it often felt like touching the device would calm it. It seemed that a common result of touching the device, after the touch-to-activate initial interaction, was that it would turn off. We came to see this as signifying a sort of reassurance, a taming of the beast of social interaction.

### Future Directions
One possible extension to the design of the kinetic sculpture that came up during development was the addition of handles to allow users to modify and bend the shape of the structure. This came from the experience that we had building it up as the motor was running. It would add another very tangible level of feedback that speaks to the fruits of collaboration.

The circuitry could be streamlined and secured to the sculpture, the wires attaching the board to the bracelets would benefit from being lengthened and made more reliable for human use.

Also a lot of work could be done on the atmosphere and framing of the interaction. Perhaps by adding posters with instructions or designing the space around it to support the themes.  
### Bibliography


### Circuit:
- MOSFET transistor for motor voltage control via external power source.
- 3 100k ohm resistors wired in series for each capacitor sensor.


---

![requirements](images/360-documentation.png)
