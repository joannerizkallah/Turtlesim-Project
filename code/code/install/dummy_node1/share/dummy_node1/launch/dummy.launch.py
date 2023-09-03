import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    ld = LaunchDescription()
    dummy_config = os.path.join(
        get_package_share_directory('dummy_node1'),
        'dummy_config',
        'dummy_config.yaml'
        )

    node=Node(
        package = 'dummy_node1',
        name = 'dummy_server',
        executable = 'dummy_cpp_node',
        parameters = [dummy_config]
    )
    ld.add_action(node)
    return ld
