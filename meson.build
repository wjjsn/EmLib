project('EmLib', 'c', 'cpp', meson_version: '>=0.60')

# 解析并暴露各个子依赖（不聚合）。
# 上游项目先 subproject('EmLib')（或 dependency('EmLib')）加载本仓库后，
# 即可单独 dependency('HAL') / dependency('CherryRB') / dependency('Hardware')
# / dependency('SEGGER_RTT') / dependency('template_schedule') 获取，
# 各子项目已在自身 meson.build 中 meson.override_dependency() 注册同名依赖。
dependency('HAL')
dependency('CherryRB')
dependency('Hardware')
dependency('SEGGER_RTT')
dependency('template_schedule')

if not meson.is_subproject()
sources = [
  'main.c',
]

exe = executable(
  'tmp',
  sources,
  dependencies : [],
  install : true,
)
endif
