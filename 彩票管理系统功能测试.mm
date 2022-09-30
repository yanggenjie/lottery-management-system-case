<map version="freeplane 1.9.13">
<!--To view this file, download free mind mapping software Freeplane from https://www.freeplane.org -->
<node TEXT="功能测试" FOLDED="false" ID="ID_696401721" CREATED="1610381621824" MODIFIED="1664192653386" STYLE="oval">
<font SIZE="18"/>
<hook NAME="MapStyle">
    <properties edgeColorConfiguration="#808080ff,#ff0000ff,#0000ffff,#00ff00ff,#ff00ffff,#00ffffff,#7c0000ff,#00007cff,#007c00ff,#7c007cff,#007c7cff,#7c7c00ff" associatedTemplateLocation="template:/standard-1.6.mm" fit_to_viewport="false"/>

<map_styles>
<stylenode LOCALIZED_TEXT="styles.root_node" STYLE="oval" UNIFORM_SHAPE="true" VGAP_QUANTITY="24 pt">
<font SIZE="24"/>
<stylenode LOCALIZED_TEXT="styles.predefined" POSITION="right" STYLE="bubble">
<stylenode LOCALIZED_TEXT="default" ID="ID_271890427" ICON_SIZE="12 pt" FORMAT_AS_HYPERLINK="false" COLOR="#000000" STYLE="fork" NUMBERED="false" FORMAT="STANDARD_FORMAT" TEXT_ALIGN="DEFAULT" MAX_WIDTH="10 cm" MIN_WIDTH="0 cm" VGAP_QUANTITY="2 pt" BORDER_WIDTH_LIKE_EDGE="false" BORDER_WIDTH="1 px" BORDER_COLOR_LIKE_EDGE="true" BORDER_COLOR="#808080" BORDER_DASH_LIKE_EDGE="false" BORDER_DASH="SOLID">
<arrowlink SHAPE="CUBIC_CURVE" COLOR="#000000" WIDTH="2" TRANSPARENCY="200" DASH="" FONT_SIZE="9" FONT_FAMILY="SansSerif" DESTINATION="ID_271890427" STARTARROW="NONE" ENDARROW="DEFAULT"/>
<font NAME="SansSerif" SIZE="10" BOLD="false" STRIKETHROUGH="false" ITALIC="false"/>
<richcontent CONTENT-TYPE="plain/auto" TYPE="DETAILS"/>
<richcontent TYPE="NOTE" CONTENT-TYPE="plain/auto"/>
<edge STYLE="bezier" COLOR="#808080" WIDTH="1" DASH="SOLID"/>
</stylenode>
<stylenode LOCALIZED_TEXT="defaultstyle.details"/>
<stylenode LOCALIZED_TEXT="defaultstyle.attributes">
<font SIZE="9"/>
</stylenode>
<stylenode LOCALIZED_TEXT="defaultstyle.note" COLOR="#000000" BACKGROUND_COLOR="#ffffff" TEXT_ALIGN="LEFT"/>
<stylenode LOCALIZED_TEXT="defaultstyle.floating">
<edge STYLE="hide_edge"/>
<cloud COLOR="#f0f0f0" SHAPE="ROUND_RECT"/>
</stylenode>
<stylenode LOCALIZED_TEXT="defaultstyle.selection" BACKGROUND_COLOR="#afd3f7" BORDER_COLOR_LIKE_EDGE="false" BORDER_COLOR="#afd3f7"/>
</stylenode>
<stylenode LOCALIZED_TEXT="styles.user-defined" POSITION="right" STYLE="bubble">
<stylenode LOCALIZED_TEXT="styles.topic" COLOR="#18898b" STYLE="fork" FORMAT="STANDARD_FORMAT">
<font NAME="Liberation Sans" SIZE="10" BOLD="true"/>
</stylenode>
<stylenode LOCALIZED_TEXT="styles.subtopic" COLOR="#cc3300" STYLE="fork" FORMAT="STANDARD_FORMAT">
<font NAME="Liberation Sans" SIZE="10" BOLD="true"/>
</stylenode>
<stylenode LOCALIZED_TEXT="styles.subsubtopic" COLOR="#669900" FORMAT="STANDARD_FORMAT">
<font NAME="Liberation Sans" SIZE="10" BOLD="true"/>
</stylenode>
<stylenode LOCALIZED_TEXT="styles.important" ID="ID_67550811" FORMAT="STANDARD_FORMAT">
<icon BUILTIN="yes"/>
<arrowlink COLOR="#003399" TRANSPARENCY="255" DESTINATION="ID_67550811"/>
</stylenode>
</stylenode>
<stylenode LOCALIZED_TEXT="styles.AutomaticLayout" POSITION="right" STYLE="bubble">
<stylenode LOCALIZED_TEXT="AutomaticLayout.level.root" COLOR="#000000" STYLE="oval" SHAPE_HORIZONTAL_MARGIN="10 pt" SHAPE_VERTICAL_MARGIN="10 pt" FORMAT="STANDARD_FORMAT">
<font SIZE="18"/>
</stylenode>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,1" COLOR="#0033ff" FORMAT="STANDARD_FORMAT">
<font SIZE="16"/>
</stylenode>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,2" COLOR="#00b439" FORMAT="STANDARD_FORMAT">
<font SIZE="14"/>
</stylenode>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,3" COLOR="#990000" FORMAT="STANDARD_FORMAT">
<font SIZE="12"/>
</stylenode>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,4" COLOR="#111111" FORMAT="STANDARD_FORMAT">
<font SIZE="10"/>
</stylenode>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,5" FORMAT="STANDARD_FORMAT"/>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,6" FORMAT="STANDARD_FORMAT"/>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,7" FORMAT="STANDARD_FORMAT"/>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,8" FORMAT="STANDARD_FORMAT"/>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,9" FORMAT="STANDARD_FORMAT"/>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,10" FORMAT="STANDARD_FORMAT"/>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,11" FORMAT="STANDARD_FORMAT"/>
</stylenode>
</stylenode>
</map_styles>
</hook>
<hook NAME="AutomaticEdgeColor" COUNTER="4" RULE="ON_BRANCH_CREATION"/>
<node TEXT="登录和注册功能" POSITION="right" ID="ID_231402346" CREATED="1664193970125" MODIFIED="1664193981886">
<edge COLOR="#00ff00"/>
<node TEXT="注册功能测试" ID="ID_372967786" CREATED="1664192653987" MODIFIED="1664193985693">
<node TEXT="1.管理员注册" ID="ID_670740764" CREATED="1664192659197" MODIFIED="1664192677542">
<node TEXT="1.用户名，密码都正确&#xd;&#xa;admin 123 123&#xd;&#xa;&#xd;&#xa;2.用户名重复&#xd;&#xa;admin 123 123&#xd;&#xa;&#xd;&#xa;3.用户名长度超出30位&#xd;&#xa;admin012345678901234567890123456789 123 123&#xd;&#xa;&#xd;&#xa;4.两次密码不一致&#xd;&#xa;admin1 123 124&#xd;&#xa;&#xd;&#xa;5.密码长度超出32位&#xd;&#xa;admin1 0123456789012345678901234567891234 0123456789012345678901234567891234&#xd;&#xa;&#xd;&#xa;6.注册第二个正确的账户&#xd;&#xa;admin1 123 123" ID="ID_1161252516" CREATED="1664192690905" MODIFIED="1664337625397" FORMAT="markdownPatternFormat" MAX_WIDTH="50 cm"/>
</node>
<node TEXT="2.公证员注册同上" ID="ID_710471258" CREATED="1664192788522" MODIFIED="1664192823585">
<node TEXT="1.用户名，密码都正确&#xd;&#xa;notary 123 123&#xd;&#xa;&#xd;&#xa;2.用户名重复&#xd;&#xa;notary 123 123&#xd;&#xa;&#xd;&#xa;3.用户名长度超出30位&#xd;&#xa;notary012345678901234567890123456789 123 123&#xd;&#xa;&#xd;&#xa;4.两次密码不一致&#xd;&#xa;notary1 123 124&#xd;&#xa;&#xd;&#xa;5.密码长度超出32位&#xd;&#xa;notary1 0123456789012345678901234567891234 0123456789012345678901234567891234&#xd;&#xa;&#xd;&#xa;6.注册第二个正确的账户&#xd;&#xa;notary1 123 123" ID="ID_1892446701" CREATED="1664193453366" MODIFIED="1664337625396" MAX_WIDTH="50 cm" FORMAT="markdownPatternFormat"/>
</node>
<node TEXT="3.彩民注册同上" ID="ID_75208996" CREATED="1664192805598" MODIFIED="1664192821551">
<node TEXT="1.用户名，密码都正确&#xd;&#xa;user 123 123&#xd;&#xa;&#xd;&#xa;2.用户名重复&#xd;&#xa;user 123 123&#xd;&#xa;&#xd;&#xa;3.用户名长度超出30位&#xd;&#xa;user012345678901234567890123456789 123 123&#xd;&#xa;&#xd;&#xa;4.两次密码不一致&#xd;&#xa;user1 123 124&#xd;&#xa;&#xd;&#xa;5.密码长度超出32位&#xd;&#xa;user1 0123456789012345678901234567891234 0123456789012345678901234567891234&#xd;&#xa;&#xd;&#xa;6.注册第二个正确的账户&#xd;&#xa;user1 123 123" ID="ID_922237912" CREATED="1664193469011" MODIFIED="1664337625394" MAX_WIDTH="50 cm" FORMAT="markdownPatternFormat"/>
</node>
</node>
<node TEXT="登录功能测试" ID="ID_208475474" CREATED="1664192826626" MODIFIED="1664193984273">
<node TEXT="1.管理员登录" ID="ID_1334655125" CREATED="1664192830408" MODIFIED="1664193115572">
<node TEXT="1.测试注册的两个账号能否正常登入对应的界面&#xa;&#xa;2.测试用户名输错3次，能否正常退出程序&#xa;&#xa;3.测试密码输错3次，能否正常退出程序" ID="ID_1599900140" CREATED="1664193115920" MODIFIED="1664337625397" FORMAT="markdownPatternFormat"/>
</node>
<node TEXT="公证员、彩民同上" ID="ID_1838448026" CREATED="1664193147995" MODIFIED="1664193157118"/>
</node>
</node>
<node TEXT="bug" POSITION="right" ID="ID_1062465668" CREATED="1664327606959" MODIFIED="1664327727835" ICON_SIZE="16 pt" FORMAT="STANDARD_FORMAT">
<edge COLOR="#ff00ff"/>
<node TEXT="1. 彩民注册的时候，有时会点击注册后，刚输入一个数，就进入死循环，一直在刷新，第二次运行的时候没有这种问题，难以复现" ID="ID_775571427" CREATED="1664327611944" MODIFIED="1664337558268" FORMAT="STANDARD_FORMAT">
<icon BUILTIN="button_cancel"/>
<node TEXT="选择彩民注册的时候，应该选择1，但不小心输入了u1，就进入死循环" ID="ID_545131133" CREATED="1664330880932" MODIFIED="1664337561789" FORMAT="STANDARD_FORMAT"/>
<node TEXT="目前使用exit(1)强制退出程序解决" ID="ID_1822456202" CREATED="1664337531736" MODIFIED="1664337561786" FORMAT="STANDARD_FORMAT"/>
</node>
<node TEXT="下注时，没有自动保存信息到文件" ID="ID_1173106087" CREATED="1664460186360" MODIFIED="1664460344379">
<icon BUILTIN="button_ok"/>
</node>
<node TEXT="用户登录时，没有读取相应的账户余额，购买记录" ID="ID_1048373750" CREATED="1664460346232" MODIFIED="1664460367875"/>
</node>
</node>
</map>
