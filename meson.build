project('EmLib', 'c', 'cpp', meson_version: '>=0.60')

dependencies = [
  dependency('HAL'),
  dependency('CherryRB'),
  dependency('Hardware'),
  dependency('SEGGER_RTT'),
  dependency('template_schedule')
]

sources = [
  'main.c',
]

exe = executable(
  'tmp',
  sources,
  dependencies : dependencies,
  install : true,
)