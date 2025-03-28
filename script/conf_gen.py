import os

json_config_file = """
{
    "modules": [
        {
            "key": "╔═══════════╗",
            "type": "custom"
        },
        {
            "key": "║ {#31} user    ║", 
            "type": "username",
            "format": "{user-name}" 
        },
        {
            "key": "║ {#32}󰇅 hname   ║",
            "type": "hname",
            "format": "{host-name}"
        },
        {
            "key": "║ {#33} distro  ║",
            "type": "distro"
        },
        {
            "key": "║ {#35} kernel  ║",
            "type": "kernel"
        },
        {
            "key": "║ {#35}󰍛 cpu     ║",
            "type": "cpu"
        },
        {
            "key": "║ {#33}󰹡 memory  ║",
            "type": "memory"
        },
        {
            "key": "║ {#32}󰉉 disk    ║",
            "type": "disk"
        },
        {
            "key": "║ {#31}󰩟 ip      ║",
            "type": "ip"
        },
        {
            "key": "║ {#31}󱑏 uptime  ║",
            "type": "uptime"
        },
        {
            "key": "╠═══════════╣",
            "type": "custom"
        },
        {
            "key": "║ {#1} colors  ║",
            "type": "colors"
        },
        {
            "key": "╚═══════════╝",
            "type": "custom"
        }
    ]
}
"""

home_user = os.path.expanduser("~")

with open(home_user+'/config_christfetch.jsonc','w') as f:
    f.write(json_config_file)

print('Config file at : {}/config_christfetch.jsonc'.format(home_user))
