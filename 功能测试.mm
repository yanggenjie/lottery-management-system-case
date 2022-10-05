<map version="freeplane 1.9.13">
<!--To view this file, download free mind mapping software Freeplane from https://www.freeplane.org -->
<node TEXT="功能测试" LOCALIZED_STYLE_REF="AutomaticLayout.level.root" FOLDED="false" ID="ID_1090958577" CREATED="1409300609620" MODIFIED="1664685647011">
<hook NAME="accessories/plugins/AutomaticLayout.properties" VALUE="ALL"/>
<font BOLD="true"/>
<hook NAME="MapStyle" background="#f9f9f8" zoom="1.301">
    <properties show_icon_for_attributes="true" edgeColorConfiguration="#808080ff,#ff0000ff,#0000ffff,#00ff00ff,#ff00ffff,#00ffffff,#7c0000ff,#00007cff,#007c00ff,#7c007cff,#007c7cff,#7c7c00ff" show_note_icons="true" associatedTemplateLocation="template:/light_nord_template.mm" fit_to_viewport="false"/>

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
<node TEXT="能够发行彩票" ID="ID_508991314" CREATED="1664878560820" MODIFIED="1664878569685">
<node TEXT="测试方法" ID="ID_1305112286" CREATED="1664878570358" MODIFIED="1664878629828">
<node TEXT="1.点击发行彩票，测试能否发行彩票，发行正确显示发行信息&#xa;&#xa;2.发行成功后，继续点击发行彩票，测试上期未开奖，能否发下一期。&#xa;&#xa;- 输入期号与上期相同，测试期号唯一性&#xa;- 输入期号与上期不同，测试能否发行多期彩票&#xa;&#xa;3.切换公证员去开奖，然后再测试能否发下一期。" ID="ID_1239598659" CREATED="1664685667066" MODIFIED="1664878586731" FORMAT="markdownPatternFormat" MAX_WIDTH="20 cm" HGAP_QUANTITY="41 pt" VSHIFT_QUANTITY="-9 pt"/>
</node>
</node>
</node>
<node TEXT="保存" ID="ID_1742065885" CREATED="1664762828517" MODIFIED="1664763578851">
<icon BUILTIN="button_ok"/>
<node TEXT="保存发行信息" ID="ID_1730402308" CREATED="1664762830514" MODIFIED="1664878502871">
<node TEXT="测试方法" ID="ID_1482205225" CREATED="1664878503080" MODIFIED="1664878506024">
<node TEXT="发行信息之后，退出程序，启动程序。&#xa;&#xa;- 登录管理员，查看发行历史，是否正确显示数据&#xa;- 登录公证员，查看发行历史，是否正确显示数据&#xa;- 登录彩民，点开下注功能，是否显示发行信息" ID="ID_935895241" CREATED="1664878506323" MODIFIED="1664878725343" FORMAT="markdownPatternFormat" MAX_WIDTH="20 cm"/>
</node>
</node>
</node>
<node TEXT="查询彩民信息" ID="ID_670724718" CREATED="1664763600204" MODIFIED="1664763606725">
<node TEXT="根据账号查询" ID="ID_753204888" CREATED="1664763617750" MODIFIED="1664763624037">
<node TEXT="测试方法" ID="ID_386509866" CREATED="1664878329861" MODIFIED="1664878329861">
<node TEXT="注册彩民账号&#xd;&#xa;- u1,123,余额10;&#xd;&#xa;- u2,123,余额100;&#xd;&#xa;- u3,123,余额1000;&#xd;&#xa;&#xd;&#xa;分别输入三个账号名，看是否正确显示账号的信息。" ID="ID_1674549305" CREATED="1664878044271" MODIFIED="1664878326730" FORMAT="markdownPatternFormat"/>
</node>
</node>
<node TEXT="根据余额区间查询" ID="ID_288864776" CREATED="1664763624197" MODIFIED="1664763632284">
<node TEXT="测试方法" ID="ID_1442609221" CREATED="1664878329861" MODIFIED="1664878329861">
<node TEXT="注册彩民账号&#xd;&#xa;- u1,123,余额10;&#xd;&#xa;- u2,123,余额100;&#xd;&#xa;- u3,123,余额1000;&#xd;&#xa;&#xd;&#xa;分别输入&#xd;&#xa;- 0-20;&#xd;&#xa;- 30-300;&#xd;&#xa;- 400-4000;&#xd;&#xa;- 0-100;&#xd;&#xa;- 0-1000;&#xd;&#xa;&#xd;&#xa;测试是否正确显示对应区间内的数据" ID="ID_260987675" CREATED="1664878044271" MODIFIED="1664878459213" FORMAT="markdownPatternFormat" MAX_WIDTH="50 cm"/>
</node>
</node>
</node>
<node TEXT="排序显示彩民信息" ID="ID_1527886717" CREATED="1664763606920" MODIFIED="1664878308323" MAX_WIDTH="20 cm">
<node TEXT="显示所有彩民信息" ID="ID_34926805" CREATED="1664878968531" MODIFIED="1664878976464">
<node TEXT="测试方法" ID="ID_618916714" CREATED="1664878820096" MODIFIED="1664878823078">
<node TEXT="注册上面的3个彩民账号，看看是否正确显示所有用户" ID="ID_1880210564" CREATED="1664879012611" MODIFIED="1664879047715"/>
</node>
</node>
<node TEXT="根据账号排序" ID="ID_1887028035" CREATED="1664763646210" MODIFIED="1664763651356">
<node TEXT="测试方法" ID="ID_1364958418" CREATED="1664878820096" MODIFIED="1664878823078">
<node TEXT="再次注册&#xa;&#xa;- u6,123，余额20&#xa;- u4,123，余额5&#xa;- u5,123，余额200&#xa;&#xa;- 先查看所有彩民信息，看看乱序的显示，&#xa;- 然后点击根据账号排序，查看此时的显示顺序。" ID="ID_214849096" CREATED="1664879050586" MODIFIED="1664879223921" FORMAT="markdownPatternFormat" MAX_WIDTH="20 cm"/>
</node>
<node TEXT="bug" ID="ID_1841456149" CREATED="1664970729533" MODIFIED="1664970731106">
<node TEXT="出现段错误，选择排序有问题" ID="ID_1934666776" CREATED="1664970731264" MODIFIED="1664970744925"/>
</node>
</node>
<node TEXT="根据彩民账号余额排序" ID="ID_1975976746" CREATED="1664763635255" MODIFIED="1664763646057">
<node TEXT="测试方法" ID="ID_1279726420" CREATED="1664878820096" MODIFIED="1664878823078">
<node TEXT="基于账号排序功能的测试步骤，再次执行&#xa;&#xa;- 先查看所有彩民信息，看看乱序的显示，&#xa;- 然后点击根据余额排序，查看此时的显示顺序。" ID="ID_847108870" CREATED="1664879050586" MODIFIED="1664879280124" FORMAT="markdownPatternFormat" MAX_WIDTH="20 cm"/>
</node>
</node>
</node>
</node>
<node TEXT="公证员功能测试" POSITION="right" ID="ID_1900632467" CREATED="1664689323290" MODIFIED="1664764212059">
<icon BUILTIN="button_ok"/>
<node TEXT="开奖" ID="ID_965002359" CREATED="1664689331588" MODIFIED="1664764233508">
<icon BUILTIN="button_ok"/>
<node TEXT="公证员能够发布开奖&#xa;&#xa;1. 能够显示开奖结果，中奖者的余额要更新&#xa;2. 中奖算法：必须有随机数。中奖算法能合理计算中奖号码的中奖金额" ID="ID_576383631" CREATED="1664879310934" MODIFIED="1664879414362" FORMAT="markdownPatternFormat"><richcontent CONTENT-TYPE="plain/auto" TYPE="DETAILS"/>
<node TEXT="测试方法" ID="ID_1997616841" CREATED="1664879284755" MODIFIED="1664879289085">
<node TEXT="1. 发行一期彩票。&#xa;2. 登录彩民1，充值22元，购买11个号码；购买完之后，彩民账户余额为0&#xa;3. 登录彩民2，充值100元，购买20个号码；购买完之后，彩民账户余额为60&#xa;4. 登录公证员，点击开奖，如有显示中奖用户，要显示中奖的用户。&#xa;5. 重新登录中奖的账号，查看余额是否更新。&#xa;&#xa;注意留意，购买完之后，登录公证员账号，查看奖池售出量应为31，奖池总额应为62" ID="ID_532331943" CREATED="1664879290470" MODIFIED="1664879843515" FORMAT="markdownPatternFormat" MAX_WIDTH="20 cm"/>
</node>
<node TEXT="bug" ID="ID_1048391722" CREATED="1664689400248" MODIFIED="1664689401405">
<node TEXT="预期：如果已经开奖，则不可以继续开奖。&#xd;&#xa;&#xd;&#xa;目前bug:可以任意开奖。" ID="ID_1847016366" CREATED="1664689402614" MODIFIED="1664880365745" FORMAT="markdownPatternFormat">
<node TEXT="已修复" ID="ID_606298373" CREATED="1664763712692" MODIFIED="1664763715299"/>
</node>
<node TEXT="开奖之后不能正确显示中奖用户，奖金发放正常，因未统计中奖用户" ID="ID_617124073" CREATED="1664903353200" MODIFIED="1664903398117">
<node TEXT="已修复" ID="ID_783798952" CREATED="1664909755902" MODIFIED="1664909758644"/>
</node>
<node TEXT="奖金发放异常，多发" ID="ID_349659439" CREATED="1664909759678" MODIFIED="1664909775686"/>
</node>
</node>
</node>
<node TEXT="查看当期发行信息" ID="ID_480436962" CREATED="1664764224308" MODIFIED="1664880136258">
<icon BUILTIN="button_ok"/>
<node TEXT="仅显示当期发行信息" ID="ID_720112773" CREATED="1664880110063" MODIFIED="1664880132367">
<node TEXT="测试方法" ID="ID_242491032" CREATED="1664880118342" MODIFIED="1664880278220">
<node TEXT="发行第一期彩票，开奖；&#xa;&#xa;发行第二期彩票&#xa;&#xa;点击测试是否仅显示第二期的信息" ID="ID_724285936" CREATED="1664880278563" MODIFIED="1664880345770" FORMAT="markdownPatternFormat"/>
</node>
<node TEXT="bug" ID="ID_1274290304" CREATED="1664695260526" MODIFIED="1664695270735">
<node TEXT="有两期发行的时候，出现段错误" ID="ID_1591975456" CREATED="1664695272108" MODIFIED="1664695284383">
<node TEXT="已修复" ID="ID_285695133" CREATED="1664764217733" MODIFIED="1664764219671"/>
</node>
</node>
</node>
</node>
<node TEXT="查看所有期发行信息" ID="ID_1108707085" CREATED="1664689336640" MODIFIED="1664880138401">
<icon BUILTIN="button_ok"/>
<node TEXT="能显示所有发行信息" ID="ID_248105901" CREATED="1664880371328" MODIFIED="1664880385662">
<node TEXT="测试方法" ID="ID_1811736994" CREATED="1664880386288" MODIFIED="1664880392632">
<arrowlink DESTINATION="ID_724285936" STARTINCLINATION="243.74999 pt;0 pt;" ENDINCLINATION="258.74999 pt;0 pt;"/>
</node>
</node>
</node>
</node>
<node TEXT="彩民功能测试" POSITION="right" ID="ID_202984358" CREATED="1664764237403" MODIFIED="1664764241154">
<node TEXT="查看个人信息" ID="ID_1969991726" CREATED="1664764302337" MODIFIED="1664877477144">
<icon BUILTIN="button_ok"/>
<node TEXT="能正确显示个人信息" ID="ID_1479486602" CREATED="1664880397172" MODIFIED="1664880408124">
<node TEXT="" ID="ID_584628320" CREATED="1664880563270" MODIFIED="1664880563270"/>
</node>
</node>
<node TEXT="修改密码" ID="ID_1065788299" CREATED="1664764355509" MODIFIED="1664877480312">
<icon BUILTIN="button_ok"/>
<node TEXT="能修改密码&#xa;- 检测旧密码是否正确，不正确提示重新输入旧密码&#xa;- 如正确，检验两次输入的新密码是否一致，不一致提示重新输入密码&#xa;- 如修改成功，下次登录前生效。" ID="ID_344784992" CREATED="1664880412872" MODIFIED="1664880552795" FORMAT="markdownPatternFormat">
<node TEXT="测试方法" ID="ID_120475795" CREATED="1664880558850" MODIFIED="1664880561584">
<node TEXT="注册u1,123;&#xd;&#xa;- 修改密码，原密码111，测试是否提示重新修改&#xd;&#xa;- 原密码123，新密码1234，新密码第二次1111，测试是否提示重新修改&#xd;&#xa;- 原密码123，新密码1234，新密码1234，测试是否提示修改成功&#xd;&#xa;- 退出登录，测试是能否用新密码登录。&#xd;&#xa;- 退出程序，重新启动，测试密码是否成功保存到文件" ID="ID_729140463" CREATED="1664880575717" MODIFIED="1664880963632" FORMAT="markdownPatternFormat" MAX_WIDTH="20 cm"/>
</node>
</node>
</node>
<node TEXT="账户充值" ID="ID_1374268560" CREATED="1664764359493" MODIFIED="1664764362337">
<node TEXT="用户能给自己的账户充值" ID="ID_963121881" CREATED="1664880985997" MODIFIED="1664881135857">
<node TEXT="测试方法" ID="ID_647783716" CREATED="1664881124311" MODIFIED="1664881176314">
<node TEXT="查看当前账户余额，充值100；再次查看信息，检查是否充值成功" ID="ID_226320524" CREATED="1664881176443" MODIFIED="1664881210315"/>
</node>
</node>
<node TEXT="购买彩票时，余额不足，要提示充值" ID="ID_363980205" CREATED="1664881137278" MODIFIED="1664881282625">
<arrowlink DESTINATION="ID_1943856096"/>
</node>
</node>
<node TEXT="下注" ID="ID_931391262" CREATED="1664764363807" MODIFIED="1664881170569">
<node TEXT="自选号码" ID="ID_1794256328" CREATED="1664764379115" MODIFIED="1664881170569" HGAP_QUANTITY="22.25 pt" VSHIFT_QUANTITY="-17.25 pt"/>
<node TEXT="机选号码" ID="ID_739458830" CREATED="1664764382002" MODIFIED="1664764385686">
<node TEXT="bug" ID="ID_1825756328" CREATED="1664863277661" MODIFIED="1664863279609">
<node TEXT="会生成乱码" ID="ID_362666432" CREATED="1664877341372" MODIFIED="1664877352059">
<node TEXT="已修复" ID="ID_1004373262" CREATED="1664863279783" MODIFIED="1664881278496">
<arrowlink DESTINATION="ID_197277470" STARTINCLINATION="-53.25 pt;34.5 pt;" ENDINCLINATION="33.75 pt;-10.5 pt;"/>
<node TEXT="已修复，是打印的时候访问越界的下标，程序也有些问题，与打印出现乱码相同，都是数组下标越界&#xa;&#xa;```c&#xa;// 原循环结束的判断条件如下&#xa;strcmp(ticketTemp-&gt;data.numStr[i], empty) != 0&#xa;//修改后如下&#xa;strcmp(ticketTemp-&gt;data.numStr[i], empty) != 0 &amp;&amp; i &lt; 5&#xa;&#xa;```&#xa;numStr是5行22列的数组，忘记对i进行限制，本来只能访问到numStr[4]的，&#xa;&#xa;由于这里是循环条件的判断，没有加i&lt;5，i会一直增长下去，&#xa;&#xa;无限循环，所以，有循环的地方，要保证循环时，数组下标不会越界，否则就会出现各种意想不到的问题。" ID="ID_328086652" CREATED="1664870777610" MODIFIED="1664881084236" FORMAT="markdownPatternFormat" MAX_WIDTH="20 cm"/>
</node>
</node>
</node>
<node TEXT="测试方法" ID="ID_862201030" CREATED="1664881222209" MODIFIED="1664881267257">
<node TEXT="- 账户余额为0，测试能否购买？是否提示余额不足？&#xa;- 给账户充值100。&#xa;- 购买11个号，查看记录。&#xa;- 切换公证员账号，查看奖池是否更新。&#xa;- 切换另外一个彩民，查看奖池的信息是否一致" ID="ID_1943856096" CREATED="1664881267526" MODIFIED="1664883482139" FORMAT="markdownPatternFormat"/>
</node>
<node TEXT="bug" ID="ID_1996172893" CREATED="1664883485204" MODIFIED="1664883486502">
<node TEXT="下注之后，奖池未更新" ID="ID_1743023149" CREATED="1664883486666" MODIFIED="1664883497277"/>
<node TEXT="下注之后，用户购买的号码数量统计有误，购买11个号码，显示15个" ID="ID_1977969516" CREATED="1664883723664" MODIFIED="1664883745178"/>
</node>
</node>
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
