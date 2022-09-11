param (
    [bool]$create_zip_package = $True,
    [bool]$create_installer = $False    
) 

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
    bazel build //:StatikaTorzo --config=windows-opt
}

$root_application = -join($root_directory, '\bazel-out\x64_windows-opt\bin')
$directory_to_copy = -join($root_application, "\Application")
$exe_to_copy = -join($root_application, "\StatikaTorzo.exe")
$root_application_release = -join($root_directory, "\Scripts\StatikaTorzo")
$exclude_file_types = @("*.pdb", "*.bazel", "*.lib-*")

# @TODO: Exclude folders (i.e. _objs)

echo "Creating release folder: $root_application_release"
New-Item -Path $root_directory -Name "StatikaTorzo" -ItemType "directory" -Force
Copy-Item -Path $directory_to_copy -Destination $root_application_release -Recurse -Exclude $exclude_file_types -Force
Copy-Item -Path $exe_to_copy -Destination $root_application_release -Force

if($create_zip_package -eq $True)
{
    echo "Creating ZIP package"
    Compress-Archive -Path $root_application_release -DestinationPath StatikaTorzo.zip -Force

    echo "Cleaning up..."
    Remove-Item -Path $root_application_release -Recurse -Force
}

if($create_installer -eq $True)
{
    echo "Creating installer"
    makensis $root_directory\Scripts\create_installer.nsi
}
