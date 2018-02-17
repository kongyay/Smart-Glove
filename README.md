# Smart Glove
## Project under topic: _"LDR(Light Dependent Resistor)-based device"_
### This project's main objective was to invent something that applies the use of LDR as unique as possible
#### Input
- LDR is used to detect whether the user's (who wears the glove) hand is open or close by programming decision based on light threshold. This method is seperated for each finger.
  - Low Light intensity (Value around close threshold) = Close 
  - High Light intensity (Value around open threshold) = Open
#### Output
- 8x8 Dot Matrix LED, controlled by rapidly shifting bits into LED to represent the pixel art we want to show. 
- Speaker, controlled by sending bits as frequency to represent each music note.
  
## Available Gesture
1. Count 0-5 (Default/Not found case)
2. Call me
3. Love
4. Rocker
5. Go!
6. Good (Thumb up)
7. Promise
8. Insult


## Algorithm
1. Open the device: User fully open his hand for 5 sec. Close his hand for 5 sec.
2. Calculate the threshold
3. Fully usable

