echo "##### Creating Windows release package #####"

Set-ExecutionPolicy -Scope CurrentUser -ExecutionPolicy Unrestricted
$ErrorActionPreference = "Stop"

$root_directory = Split-Path -Path $PSScriptRoot -Parent
cd $root_directory
echo "Root directory: $PWD"

if(!(Test-Path -Path $root_directory\bazel-out))
{
    echo "Building application in release mode"
    bazel --version
    bazel build //:main --config=windows-opt
}

$root_application = -join($root_directory, '\bazel-out\x64_windows-opt\bin')
$directory_to_copy = -join($root_application, "\Application")
$exe_to_copy = -join($root_application, "\main.exe")
$root_application_release = -join($root_directory, "\StatikaTorzo")
$exclude_file_types = @("*.pdb", "*.bazel", "*.lib-*")

# @TODO: Exclude folders (i.e. _objs)

echo "Creating release folder: $root_application_release"
New-Item -Path $root_directory -Name "StatikaTorzo" -ItemType "directory" -Force
Copy-Item -Path $directory_to_copy -Destination $root_application_release -Recurse -Exclude $exclude_file_types -Force
Copy-Item -Path $exe_to_copy -Destination $root_application_release -Force

echo "Creating ZIP package"
Compress-Archive -Path $root_application_release -DestinationPath StatikaTorzo.zip -Force

echo "Cleaning up..."
Remove-Item -Path $root_application_release -Recurse -Force