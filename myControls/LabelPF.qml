import QtQuick 2.5

import "../myScripts/Styles.js" as ScriptStyles

Text {
    id: root

    font.pixelSize: global_scale_factor * 50
    font.family: ScriptStyles.DefaultStyle.labelFont

}
