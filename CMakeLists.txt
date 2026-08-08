cmake_minimum_required(VERSION 3.22)
project(EmLib LANGUAGES C CXX ASM)

# 通过注释和解除注释来使用外部库（子项目位于 subprojects/ 下）
# 作为子目录被引用（add_subdirectory(EmLib)）后，以下库目标对上层全局可见，
# 上游可直接 target_link_libraries(<目标> PRIVATE CherryRB SEGGER_RTT HAL Hardware template_schedule)
add_subdirectory(subprojects/CherryRB)
add_subdirectory(subprojects/SEGGER_RTT)
add_subdirectory(subprojects/HAL)
add_subdirectory(subprojects/Hardware)
add_subdirectory(subprojects/template_schedule)
