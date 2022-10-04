<map version="freeplane 1.9.13">
<!--To view this file, download free mind mapping software Freeplane from https://www.freeplane.org -->
<node TEXT="功能测试" LOCALIZED_STYLE_REF="AutomaticLayout.level.root" FOLDED="false" ID="ID_1090958577" CREATED="1409300609620" MODIFIED="1664685647011">
<hook NAME="accessories/plugins/AutomaticLayout.properties" VALUE="ALL"/>
<font BOLD="true"/>
<hook NAME="MapStyle" background="#f9f9f8">
    <properties show_icon_for_attributes="true" edgeColorConfiguration="#808080ff,#ff0000ff,#0000ffff,#00ff00ff,#ff00ffff,#00ffffff,#7c0000ff,#00007cff,#007c00ff,#7c007cff,#007c7cff,#7c7c00ff" show_note_icons="true" fit_to_viewport="false" associatedTemplateLocation="template:/light_nord_template.mm"/>

<map_styles>
<stylenode LOCALIZED_TEXT="styles.root_node" STYLE="oval" UNIFORM_SHAPE="true" VGAP_QUANTITY="24 pt">
<font SIZE="24"/>
<stylenode LOCALIZED_TEXT="styles.predefined" POSITION="right" STYLE="bubble">
<stylenode LOCALIZED_TEXT="default" ID="ID_506805493" ICON_SIZE="12 pt" FORMAT_AS_HYPERLINK="false" COLOR="#484747" BACKGROUND_COLOR="#efefef" STYLE="bubble" SHAPE_HORIZONTAL_MARGIN="8 pt" SHAPE_VERTICAL_MARGIN="5 pt" BORDER_WIDTH_LIKE_EDGE="false" BORDER_WIDTH="1.9 px" BORDER_COLOR_LIKE_EDGE="false" BORDER_COLOR="#8fbcbb" BORDER_DASH_LIKE_EDGE="true" BORDER_DASH="SOLID">
<arrowlink SHAPE="CUBIC_CURVE" COLOR="#000000" WIDTH="2" TRANSPARENCY="200" DASH="" FONT_SIZE="9" FONT_FAMILY="SansSerif" DESTINATION="ID_506805493" STARTARROW="NONE" ENDARROW="DEFAULT"/>
<font NAME="SansSerif" SIZE="11" BOLD="false" STRIKETHROUGH="false" ITALIC="false"/>
<edge STYLE="bezier" COLOR="#2e3440" WIDTH="3" DASH="SOLID"/>
<richcontent CONTENT-TYPE="plain/auto" TYPE="DETAILS"/>
<richcontent TYPE="NOTE" CONTENT-TYPE="plain/auto"/>
</stylenode>
<stylenode LOCALIZED_TEXT="defaultstyle.details" COLOR="#ffffff" BACKGROUND_COLOR="#2e3440" BORDER_WIDTH_LIKE_EDGE="false" BORDER_WIDTH="1.9 px" BORDER_COLOR_LIKE_EDGE="false" BORDER_COLOR="#f0f0f0" BORDER_DASH_LIKE_EDGE="true">
<font SIZE="11" BOLD="false" ITALIC="false"/>
</stylenode>
<stylenode LOCALIZED_TEXT="defaultstyle.attributes">
<font SIZE="10"/>
</stylenode>
<stylenode LOCALIZED_TEXT="defaultstyle.note" COLOR="#000000" BACKGROUND_COLOR="#f6f9a1" TEXT_ALIGN="LEFT">
<icon BUILTIN="clock2"/>
<font SIZE="10"/>
</stylenode>
<stylenode LOCALIZED_TEXT="defaultstyle.floating">
<edge STYLE="hide_edge"/>
<cloud COLOR="#f0f0f0" SHAPE="ROUND_RECT"/>
</stylenode>
<stylenode LOCALIZED_TEXT="defaultstyle.selection" COLOR="#eceff4" BACKGROUND_COLOR="#bf616a" BORDER_COLOR_LIKE_EDGE="false" BORDER_COLOR="#bf616a"/>
</stylenode>
<stylenode LOCALIZED_TEXT="styles.user-defined" POSITION="right" STYLE="bubble">
<stylenode LOCALIZED_TEXT="styles.important" ID="ID_915433779" BORDER_COLOR="#bf616a">
<icon BUILTIN="yes"/>
<arrowlink COLOR="#bf616a" TRANSPARENCY="255" DESTINATION="ID_915433779"/>
<font NAME="Ubuntu" SIZE="14"/>
<edge COLOR="#bf616a"/>
</stylenode>
</stylenode>
<stylenode LOCALIZED_TEXT="styles.AutomaticLayout" POSITION="right" STYLE="bubble">
<stylenode LOCALIZED_TEXT="AutomaticLayout.level.root" COLOR="#ffffff" BACKGROUND_COLOR="#484747" STYLE="bubble" SHAPE_HORIZONTAL_MARGIN="10 pt" SHAPE_VERTICAL_MARGIN="10 pt">
<font SIZE="18"/>
</stylenode>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,1" COLOR="#eceff4" BACKGROUND_COLOR="#d08770" STYLE="bubble" SHAPE_HORIZONTAL_MARGIN="8 pt" SHAPE_VERTICAL_MARGIN="5 pt">
<font SIZE="16"/>
</stylenode>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,2" COLOR="#3b4252" BACKGROUND_COLOR="#ebcb8b">
<font SIZE="14"/>
</stylenode>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,3" COLOR="#2e3440" BACKGROUND_COLOR="#a3be8c">
<font SIZE="12"/>
</stylenode>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,4" COLOR="#2e3440" BACKGROUND_COLOR="#b48ead">
<font SIZE="11"/>
</stylenode>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,5" COLOR="#e5e9f0" BACKGROUND_COLOR="#5e81ac">
<font SIZE="11"/>
</stylenode>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,6" BACKGROUND_COLOR="#81a1c1">
<font SIZE="10"/>
</stylenode>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,7" BACKGROUND_COLOR="#88c0d0">
<font SIZE="10"/>
</stylenode>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,8" BACKGROUND_COLOR="#8fbcbb">
<font SIZE="10"/>
</stylenode>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,9" BACKGROUND_COLOR="#d8dee9">
<font SIZE="10"/>
</stylenode>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,10" BACKGROUND_COLOR="#e5e9f0">
<font SIZE="9"/>
</stylenode>
</stylenode>
</stylenode>
</map_styles>
</hook>
<node TEXT="管理员功能测试" POSITION="right" ID="ID_290880388" CREATED="1664685647384" MODIFIED="1664685654634">
<node TEXT="发行彩票" ID="ID_1356870436" CREATED="1664685654767" MODIFIED="1664763580987">
<icon BUILTIN="button_ok"/>
<node TEXT="管理员能发行某一期彩票(上期已经开奖才能发布下一期)&#xa;&#xa;1.点击发行彩票，检查能否发行成功。正确显示发行信息&#xa;&#xa;2.发行成功后，继续点击发行彩票，测试上期未开奖，能否发下一期。&#xa;- 期号与上期相同，&#xa;- 期号与上期不同 &#xa;&#xa;3.切换公证员去开奖，然后再测试能否发下一期。" ID="ID_1239598659" CREATED="1664685667066" MODIFIED="1664762803625" FORMAT="markdownPatternFormat"/>
</node>
<node TEXT="保存" FOLDED="true" ID="ID_1742065885" CREATED="1664762828517" MODIFIED="1664763578851">
<icon BUILTIN="button_ok"/>
<node TEXT="发行之后，保存到文件" ID="ID_1730402308" CREATED="1664762830514" MODIFIED="1664762840028"/>
<node TEXT="然后，退出程序，重新启动，测试能否正确读取发行信息" ID="ID_1488988287" CREATED="1664762840338" MODIFIED="1664762870667">
<node TEXT="应在程序启动时读取，所有账号通用" ID="ID_1644140002" CREATED="1664762940326" MODIFIED="1664763273940"/>
</node>
</node>
<node TEXT="查询彩民信息" ID="ID_670724718" CREATED="1664763600204" MODIFIED="1664763606725">
<node TEXT="根据账号查询" ID="ID_753204888" CREATED="1664763617750" MODIFIED="1664763624037"/>
<node TEXT="根据余额区间查询" ID="ID_288864776" CREATED="1664763624197" MODIFIED="1664763632284"/>
</node>
<node TEXT="排序" ID="ID_1527886717" CREATED="1664763606920" MODIFIED="1664763608798">
<node TEXT="根据账号排序" ID="ID_1887028035" CREATED="1664763646210" MODIFIED="1664763651356"/>
<node TEXT="根据彩民账号余额排序" ID="ID_1975976746" CREATED="1664763635255" MODIFIED="1664763646057"/>
</node>
</node>
<node TEXT="公证员功能测试" POSITION="right" ID="ID_1900632467" CREATED="1664689323290" MODIFIED="1664764212059">
<icon BUILTIN="button_ok"/>
<node TEXT="开奖" ID="ID_965002359" CREATED="1664689331588" MODIFIED="1664764233508">
<icon BUILTIN="button_ok"/>
<node TEXT="bug" ID="ID_1048391722" CREATED="1664689400248" MODIFIED="1664689401405">
<node TEXT="预期：如果已经开奖，则不可以继续开奖。&#xd;&#xa;&#xd;&#xa;目前bug:可以任意开奖。" ID="ID_1847016366" CREATED="1664689402614" MODIFIED="1664763711811" FORMAT="markdownPatternFormat">
<icon BUILTIN="button_ok"/>
<node TEXT="已修复" ID="ID_606298373" CREATED="1664763712692" MODIFIED="1664763715299"/>
</node>
</node>
</node>
<node TEXT="查看当前彩票信息" ID="ID_480436962" CREATED="1664764224308" MODIFIED="1664764233507">
<icon BUILTIN="button_ok"/>
</node>
<node TEXT="查看所有期彩票信息" ID="ID_1108707085" CREATED="1664689336640" MODIFIED="1664764233508">
<icon BUILTIN="button_ok"/>
<node TEXT="bug" ID="ID_1274290304" CREATED="1664695260526" MODIFIED="1664695270735">
<node TEXT="有两期发行的时候，出现段错误" ID="ID_1591975456" CREATED="1664695272108" MODIFIED="1664695284383">
<node TEXT="已修复" ID="ID_285695133" CREATED="1664764217733" MODIFIED="1664764219671"/>
</node>
</node>
</node>
</node>
<node TEXT="彩民功能测试" POSITION="right" ID="ID_202984358" CREATED="1664764237403" MODIFIED="1664764241154">
<node TEXT="查看个人信息" ID="ID_1969991726" CREATED="1664764302337" MODIFIED="1664764355290">
<node TEXT="" ID="ID_1074766830" CREATED="1664764393398" MODIFIED="1664764393398"/>
</node>
<node TEXT="修改密码" ID="ID_1065788299" CREATED="1664764355509" MODIFIED="1664764359024"/>
<node TEXT="账户充值" ID="ID_1374268560" CREATED="1664764359493" MODIFIED="1664764362337"/>
<node TEXT="下注" ID="ID_931391262" CREATED="1664764363807" MODIFIED="1664764365188">
<node TEXT="自选号码" ID="ID_1794256328" CREATED="1664764379115" MODIFIED="1664764381868"/>
<node TEXT="机选号码" ID="ID_739458830" CREATED="1664764382002" MODIFIED="1664764385686"/>
</node>
<node TEXT="注销" ID="ID_1913534319" CREATED="1664764366864" MODIFIED="1664764368762"/>
<node TEXT="查看历史记录" ID="ID_197277470" CREATED="1664764369961" MODIFIED="1664764373696"/>
</node>
<node TEXT="注册" POSITION="right" ID="ID_1919224523" CREATED="1664757457409" MODIFIED="1664758083683">
<icon BUILTIN="button_ok"/>
<node TEXT="注册有密码确认" ID="ID_334181811" CREATED="1664757466463" MODIFIED="1664764268411">
<icon BUILTIN="button_ok"/>
</node>
<node TEXT="注册之后，可以登录系统" ID="ID_1593215034" CREATED="1664758048548" MODIFIED="1664764268411">
<icon BUILTIN="button_ok"/>
</node>
<node TEXT="退出程序之后，重新运行，可以使用之前注册好的号码" ID="ID_288606543" CREATED="1664757496967" MODIFIED="1664764268411">
<icon BUILTIN="button_ok"/>
</node>
</node>
<node TEXT="登录" POSITION="right" ID="ID_1417212176" CREATED="1664764274750" MODIFIED="1664764299371">
<icon BUILTIN="button_ok"/>
<node TEXT="可以自动判断登录的账号，进入不同权限的界面" ID="ID_829868752" CREATED="1664764280279" MODIFIED="1664764296315">
<icon BUILTIN="button_ok"/>
</node>
</node>
</node>
</map>
