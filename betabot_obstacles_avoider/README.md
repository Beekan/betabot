# Betabot Obstacle avoider

- [Betabot Obstacle avoider](#betabot-obstacle-avoider)
  - [Project Description](#project-description)
  - [After you implement the pkg state your reflection below](#after-you-implement-the-pkg-state-your-reflection-below)
    - [How did you plan the task?](#how-did-you-plan-the-task)
    - [what is your logic?](#what-is-your-logic)
    - [What ROS REPs did you used?](#what-ros-reps-did-you-used)
    - [How we could increase the overall performance?](#how-we-could-increase-the-overall-performance)
    - [List the most time consuming problems you faced](#list-the-most-time-consuming-problems-you-faced)
    - [Demo](#demo)
    - [Screenshot](#screenshot)
      - [NAME:](#name)
      - [ID:](#id)

## Project Description 

Create a ROS package with custom nodes c++/python to move the
betabot randomly in gazebo, the movement should be triggered then the robot
moves randomly while avoid objects based on laser scans reading based on the laser
scans.


>NOTE: DON'T process one ray of the laser scans array or it will be considered ultrasonic/IR sensor.try to come up with approach thats use the laser full potential. 

>To make you project standout try not to visit any place twice.

---

## After you implement the pkg state your reflection below

### How did you plan the task?

The Bot would get the depth of the straight ahead ray and if less than a certain value then it would rotate until the depth given by that ray would decrease below the given threshhold .

### what is your logic?
I thought of multiple things and failed such as implementing it as an action, but creating the goal was more complex than it needed to be. I then tried to implement it as a service but the the nature of the service being a one time call and then after the service is serviced nothing happens did not fit the nature of this task by being passive. So i then implemented it simply by a subscriber and a puplisher which acts passively and updates automatically.The distance is updated automatically by the subscriber and stored in a class variable and the publisher is publishes either rotational speed or linear speed according to the distance read. To improve the preformance the distance is also checked at different angles.

### What ROS REPs did you used?
Rep 128/144 and cpp style conventions

### How we could increase the overall performance?
instead of using a single ray to determine the depth straight ahead the depth could be calculated by taking into account the 360 rays around the bot.
### List the most time consuming problems you faced
finding the ray that pointed straight ahead from the bot as the sensor is put at a skewed angle in the description. 

---

### Demo
Add unlisted youtube/drive video

[Demo](yourlinkhere)

### Screenshot

[image](yourscreenshot)

---

#### NAME:Mohamed Mostafa
#### ID:201600236

---
