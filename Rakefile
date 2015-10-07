require 'rake/builder'

GTEST_DEPENDENCIES = %w(pthread)
LIBRARY_DEPENDENCIES = %w(sqlite3)

Rake::Builder.new do | builder |
  builder.task_namespace       = :i386
  builder.target               = 'libactive_record_sqlite_i386.a'
  builder.architecture         = 'i386'
  builder.source_search_paths  = [ 'src' ]
  builder.installable_headers  = [ 'include/**/*.h' ]
  builder.objects_path         = 'objects_i386'
  builder.include_paths        = [ 'include' ]
  builder.library_dependencies = LIBRARY_DEPENDENCIES
end

Rake::Builder.new do | builder |
  builder.task_namespace       = :x86_64
  builder.target               = 'libactive_record_sqlite_x86_64.a'
  builder.architecture         = 'x86_64'
  builder.source_search_paths  = [ 'src' ]
  builder.installable_headers  = [ 'include/**/*.h' ]
  builder.objects_path         = 'objects_x86_64'
  builder.include_paths        = [ 'include' ]
  builder.library_dependencies = LIBRARY_DEPENDENCIES
end

Rake::Builder.new do | builder |
  builder.task_namespace       = :x86_64_profiled
  builder.target               = 'libactive_record_sqlite_x86_64_profiled.a'
  builder.architecture         = 'x86_64'
  builder.source_search_paths  = [ 'src' ]
  builder.installable_headers  = [ 'include/**/*.h' ]
  builder.compilation_options  = [ '-pg' ]
  builder.objects_path         = 'objects_x86_64_profiled'
  builder.include_paths        = [ 'include' ]
  builder.library_dependencies = LIBRARY_DEPENDENCIES
end

Rake::Builder.new do | builder |
  builder.task_namespace       = :test
  builder.target               = 'active_record_test'
  builder.architecture         = 'x86_64'
  builder.source_search_paths  = [ 'test' ]
  builder.installable_headers  = [ 'test' ]
  builder.objects_path         = 'test/objects_test'
  builder.include_paths        = [ 'include', 'test' ]
  builder.library_dependencies = [ 'gtest', 'active_record_sqlite_x86_64' ] + LIBRARY_DEPENDENCIES + GTEST_DEPENDENCIES
  builder.library_paths        = [ 'objects_x86_64' ]
  builder.linker_options       = [ '-L.' ]
  builder.target_prerequisites = [ :'rake:x86_64' ]
  builder.default_task         = :run
end

Rake::Builder.new do | builder |
  builder.task_namespace       = :single_test
  builder.target               = 'single_test'
  builder.architecture         = 'x86_64'
  builder.source_search_paths  = [ 'test/base_test.cpp', 'test/test_helper.cpp', 'test/main.cpp' ]
  builder.installable_headers  = [ 'test' ]
  builder.objects_path         = 'test/objects_single_test'
  builder.include_paths        = [ 'include', 'test' ]
  builder.library_dependencies = [ 'gtest', 'active_record_sqlite_x86_64' ] + LIBRARY_DEPENDENCIES + GTEST_DEPENDENCIES
  builder.library_paths        = [ 'objects_x86_64' ]
  builder.linker_options       = [ '-L.' ]
  builder.target_prerequisites = [ :'rake:x86_64' ]
  builder.default_task         = [ :run ]
end
