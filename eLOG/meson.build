elog_src = files('elog.cpp')

elog_dep = declare_dependency(
  sources: elog_src,
  include_directories: include_directories('.'),
)

meson.override_dependency('eLOG', elog_dep)
