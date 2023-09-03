import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    ld = LaunchDescription()
    dummy_config = os.path.join(
        get_package_share_directory('dummy_node2'),
        'dummy_cpp_node',
        'dummy_cpp_node'
        )

    node=Node(
        package = 'dummy_node2',
        name = 'dummy_cpp_node',
        executable = 'dummy_cpp_node',
        parameters = [dummy_config]
    )
    ld.add_action(node)
    return ld
