#!/bin/bash

cross_ascii=$(cat <<'EOF'
$$$$$$\   $$\                 $$\             $$\     $$$$$$$$\         $$\               $$\       
$$  __$$\ $$ |                \__|            $$ |    $$  _____|        $$ |              $$ |      
$$ /  \__|$$$$$$$\   $$$$$$\  $$\  $$$$$$$\ $$$$$$\   $$ |    $$$$$$\ $$$$$$\    $$$$$$$\ $$$$$$$\  
$$ |      $$  __$$\ $$  __$$\ $$ |$$  _____|\_$$  _|  $$$$$\ $$  __$$\\_$$  _|  $$  _____|$$  __$$\ 
$$ |      $$ |  $$ |$$ |  \__|$$ |\$$$$$$\    $$ |    $$  __|$$$$$$$$ | $$ |    $$ /      $$ |  $$ |
$$ |  $$\ $$ |  $$ |$$ |      $$ | \____$$\   $$ |$$\ $$ |   $$   ____| $$ |$$\ $$ |      $$ |  $$ |
\$$$$$$  |$$ |  $$ |$$ |      $$ |$$$$$$$  |  \$$$$  |$$ |   \$$$$$$$\  \$$$$  |\$$$$$$$\ $$ |  $$ |
 \______/ \__|  \__|\__|      \__|\_______/    \____/ \__|    \_______|  \____/  \_______|\__|  \__|
                                                                                                                                                                                                                                                                                                    
EOF
)

# echo "$cross_ascii"

cf_path="$HOME/.config/christfetch";
json_path="$HOME/.config/christfetch/examples";
gospel_path="$HOME/.config/christfetch/gospels/";

rm -r $cf_path 2> /dev/null ;
rm -r $json_path 2> /dev/null;


if [[  ! -d "$cf_path" ]];then
    mkdir -p "$cf_path" ;
    cp -r examples $json_path
    cp -r gospel $gospel_path
fi 

chmod -R 775 "$cf_path" 2> /dev/null;
