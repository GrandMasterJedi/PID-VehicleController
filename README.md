[image1]: ./img/straight.png "im1"
[image2]: ./img/curve.png "im2"


# Demo of PID (Proportional Integral Derivative) Controller for Vehicle Steering

Within a simulated environment a vehicle drives autonomously a virtual circuit. The vehicle tries to stay in the center of the circuit lane as the PID controller, implemented in c++, controls the steering angle of the vehicle.  

This project is my solution to term 2, assignment 4 of the Udacity Self-Driving Car Engineer Nanodegree Program


## Data Flow
* The simulator takes data from the PID and provides cross-trach error (CTE), previous throttle and yaw. 
* The PID submit a new steering angle and adjust throttle value (speed) to the simulator


## Output
The vehicle run in the simulated circuit. The examples below show the vehicle running in a straight circuit segment, whith a speed exceeding 30mph and the vehicle behavior in a tight curvature.  
![alt text][image1]
![alt text][image2]

---

## Dependencies

* cmake >= 3.5
* All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 


--- 

## Reflection

### Describe the effect each of the P, I, D components had in your implementation.
In this implementation the PID controller is used to directly control only the steering angle. The speed (throttle) is calibrated based the steering angle. The P, I, and D components have each a function to control steering. On top of the "cross tracking error" (CTE), t
* The `P` (proportional) component control the short run steering variation. If this value is high, the vehicle tends to oscillate around the trajectory, causing an unconformable ride. On the other side, if this value is too low, the vehicle is not able to turn enough around corners, causing the vehicle to go off track.
* The `D` (derivative or differential) component is a steering counterweight. If this value is too high then vehicle tend to turn too slowly causing issues around corners, while, if this value is too low, then there is no adjustment to the steering rate so the vehicle may oscillate too much.
* With the `I` (integral) component we keep track of all previous CTEs, thus it is a long range steering component. When this component is too high, the vehicle has too much memory and tend to change direction abruptly. 

### Describe how the final hyperparameters were chosen
I choose the final hyperparameters manually by experimenting in the simulation. For example, when I observed the vehicle oscillate too much then I first decrease `P` or increase `D`. The parameter value for the integral component `I` is set close to 0.

I experiment different value for throttle as well. Fix and low value for throttle worked fine the resulting speed was too low. In my implementation I made the throttle value dependent on steering value, such that when the steering value is high, the throttle value is low. On the contrary, when there is no steering, the throttle value increases.


---
## References
* Project [Master Repository](https://github.com/udacity/CarND-PID-Control-Project)



