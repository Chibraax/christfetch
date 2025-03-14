script_folder="/mnt/homecrypted/wbruce/script/c++/Christfetch/build"
echo "echo Restoring environment" > "$script_folder/deactivate_conanbuildenv-release-x86_64.sh"
for v in PATH
do
    is_defined="true"
    value=$(printenv $v) || is_defined="" || true
    if [ -n "$value" ] || [ -n "$is_defined" ]
    then
        echo export "$v='$value'" >> "$script_folder/deactivate_conanbuildenv-release-x86_64.sh"
    else
        echo unset $v >> "$script_folder/deactivate_conanbuildenv-release-x86_64.sh"
    fi
done


export PATH="/home/wbruce/.conan2/p/cmake5a09891eb5f57/p/bin:$PATH"