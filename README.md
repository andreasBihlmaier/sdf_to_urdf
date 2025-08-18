# sdf_to_urdf

A simple ROS 2 tool to convert [SDF files](http://sdformat.org/) to [URDF](https://docs.ros.org/en/rolling/Tutorials/Intermediate/URDF/URDF-Main.html) using `urdfdom` and `sdformat_urdf`.


## Usage
After building, source your workspace and run:

```sh
ros2 run sdf_to_urdf sdf_to_urdf <input.sdf> <output.urdf>
```
- `<input.sdf>`: Path to the input SDF file
- `<output.urdf>`: Path to save the converted URDF file


## Limitations
The limitations listed in https://github.com/ros/sdformat_urdf/tree/rolling/sdformat_urdf apply.


## Notes
- `urdf::exportURDF()` is deprecated but available in Jazzy (tested) and Kilted (not tested). However, the function has been [removed in Rolling as of Jun 17 2025](https://github.com/ros/urdfdom/pull/217). There is a [feature request for a replacement](https://github.com/ros/urdfdom/issues/199).


## License
Apache-2.0