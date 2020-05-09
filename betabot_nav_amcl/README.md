# Betabot Localization and Navigation

- [Betabot Localization and Navigation](#betabot-localization-and-navigation)
  - [Project Description](#project-description)
  - [GUID](#guid)
  - [Project Rubric](#project-rubric)
  - [After you implement the pkg state your reflection below](#after-you-implement-the-pkg-state-your-reflection-below)
  - [Part I: Map (map_server)](#part-i-map-mapserver)
    - [In your own words how maps are represented in ROS?](#in-your-own-words-how-maps-are-represented-in-ros)
    - [State 5 algorithm for SLAM and the ROS implementation](#state-5-algorithm-for-slam-and-the-ros-implementation)
  - [Part II: Localization (amcl)](#part-ii-localization-amcl)
    - [In your own words how amcl works?](#in-your-own-words-how-amcl-works)
    - [Is there other better approaches to localize your robot rather than amcl?](#is-there-other-better-approaches-to-localize-your-robot-rather-than-amcl)
    - [What are the amcl limitations or the fail cases?](#what-are-the-amcl-limitations-or-the-fail-cases)
    - [Is amcl used in domain rather than Robotics?](#is-amcl-used-in-domain-rather-than-robotics)
  - [Part III: Navigation (move_base)](#part-iii-navigation-movebase)
    - [How many official local planner available in ROS?](#how-many-official-local-planner-available-in-ros)
    - [which local planner did you use?](#which-local-planner-did-you-use)
    - [In your own words how the local planner you selected works?](#in-your-own-words-how-the-local-planner-you-selected-works)
    - [How many official global planner available in ROS?](#how-many-official-global-planner-available-in-ros)
    - [which global planner did you use?](#which-global-planner-did-you-use)
    - [In your own words how the global planner you selected works?](#in-your-own-words-how-the-global-planner-you-selected-works)
    - [State your suggestion increase the overall performance?](#state-your-suggestion-increase-the-overall-performance)
    - [List the most time consuming problems you faced](#list-the-most-time-consuming-problems-you-faced)
    - [Demos](#demos)
    - [Screenshots](#screenshots)
      - [NAME:](#name)
      - [ID:](#id)

## Project Description 

Create a ROS package with custom launch files to localize the robot in an environment given the map and also to autonomous navigation. 

*Use the given [map](map/map2d.yaml) for the myoffice world [here](../betabot_gazebo/worlds/myoffice.world)* 

<p float="center">
  <img src="img/myoffice.png" width="589" /> 
  <img src="img/map2d.png" width="500" />
</p>


>NOTE: For the given map and a world the betabot robot should localize it self and move from currant pose to a given goal autonomously

## GUID
Follow where am I project from Udacity Software Robotics Engineer Nanodegree.

---
## Project Rubric

![rubric](img/reviews.jpg) 

---

## After you implement the pkg state your reflection below 

---
## Part I: Map (map_server)

###  In your own words how maps are represented in ROS?

The final map is a culmination of multiple layers below it where the final map is a range of values from 0 to 255. 

###  State 5 algorithm for SLAM and the ROS implementation

| SLAM Algorithm | ROS implementation |
|:--------------:|:------------------:|
|     GMapping   |      gmapping      |
|                |                    |
|                |                    |
|                |                    |
|                |                    |

---

## Part II: Localization (amcl)

### In your own words how amcl works?

The algorithm works by calculating a probability distribution of the bot position according the different inputs the algorithm subscribes such as the given cost maps. The Distribution calculated is then sampled thus could be visualized that the position with higher number of points is more probable to be the actual position of the robot. This allows the algorithm to be more versitile than EKF for example as the algorithm only cares about the sampled points not the actual model of the distribution.

### Is there other better approaches to localize your robot rather than amcl?

MRPT particle filtering algorithm could be used

### What are the amcl limitations or the fail cases?

If there is no refrence found or the bot was put in a room with similiar walls then the probability would diverge. It is also limited by being computationaly expensive

### Is amcl used in domain rather than Robotics?
it could be used to describe the probability distribution of any variable.

---

## Part III: Navigation (move_base)

### How many official local planner available in ROS?

6 Local planners, base_local_planner,dwa_local_planner,asr_ftc_local_planner,teb_local_planner,eband_local_planner,adaptive_local_planner

### which local planner did you use?

base_local_planner

### In your own words how the local planner you selected works?

The local map is generated using an array of sensors. The map is then used to determine the path that would result in the least collisions.

### How many official global planner available in ROS?

5

### which global planner did you use?

Navfn

### In your own words how the global planner you selected works?

The algorithm divides the map into seperate pixels where each pixel is a state, a shortest path algorithm is then implemented.

---

### State your suggestion increase the overall performance?

Use models of better sensors with less margin of error and although it might increase the computational complexity but increasing the number of samples would better the performance.

### List the most time consuming problems you faced
Aligining the map correctly but the final demo is used using the given map and setting the names of the topics and tuning  the configuration files correctly.

---

### Demos
Add unlisted youtube/drive videos

[Demo](yourlinkhere)

### Screenshots
1. rviz with all navigation launchers from turtulbot
2. gazebo

![image](yourscreenshot)

---

#### NAME:Mohamed Moatafa
#### ID:201600236

---
