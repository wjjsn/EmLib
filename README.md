# EmLib

嵌入式常用库集合（Meson wrap 形式管理子依赖），通过 wrap 引入以下子项目：

| 子项目 | 说明 |
| --- | --- |
| `CherryRB` | 环形缓冲区 |
| `HAL` | 硬件抽象层（header-only） |
| `Hardware` | 硬件驱动（OLED 字体等） |
| `SEGGER_RTT` | SEGGER RTT 调试输出 |
| `template_schedule` | 静态定时器调度（C++20） |


## 作为子项目使用

### Meson

等我用的时候再写

<del>
在消费方项目中：
```meson
subproject('EmLib')
hal_dep    = dependency('HAL')
cherryrb   = dependency('CherryRB')
hardware   = dependency('Hardware')
segger_rtt = dependency('SEGGER_RTT')
schedule   = dependency('template_schedule')
executable('app', 'main.cpp', dependencies : [hal_dep, cherryrb, hardware, segger_rtt, schedule])
```
各子依赖由自身 `meson.build` 中 `meson.override_dependency()` 注册，加载 `EmLib` 后可单独获取。消费方需自行设置 `cpp_std`（`template_schedule` 需要 C++20）。
</del>

### CMake

```sh
git clone https://github.com/wjjsn/EmLib.git
cd EmLib
meson setup build
```

在消费方项目中：

```cmake
add_subdirectory(path/to/EmLib)

target_link_libraries(<YOUR_APP> PRIVATE CherryRB SEGGER_RTT HAL Hardware template_schedule)
```

导入后暴露以下库目标：`CherryRB`、`SEGGER_RTT`、`HAL`、`Hardware`、`template_schedule`。

### 注意事项

- 顶层 `CMakeLists.txt` 只负责导入子库，不构建可执行文件。
- `SEGGER_RTT` 的 `SEGGER_RTT_ASM_ARMv7M.S` 为 ARM 汇编，在 x86 主机上编译会报错，不需要时注释掉 `SEGGER_RTT/CMakeLists.txt` 中对应行。
