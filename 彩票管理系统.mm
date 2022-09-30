<map version="freeplane 1.9.13">
<!--To view this file, download free mind mapping software Freeplane from https://www.freeplane.org -->
<node TEXT="彩票管理系统" LOCALIZED_STYLE_REF="AutomaticLayout.level.root" FOLDED="false" ID="ID_1090958577" CREATED="1409300609620" MODIFIED="1664470320139" VGAP_QUANTITY="2 pt">
<hook NAME="accessories/plugins/AutomaticLayout.properties" VALUE="ALL"/>
<font BOLD="true"/>
<hook NAME="MapStyle" background="#f9f9f8" zoom="0.455">
    <properties show_icon_for_attributes="true" edgeColorConfiguration="#808080ff,#ff0000ff,#0000ffff,#00ff00ff,#ff00ffff,#00ffffff,#7c0000ff,#00007cff,#007c00ff,#7c007cff,#007c7cff,#7c7c00ff" show_notes_in_map="true" show_note_icons="true" associatedTemplateLocation="template:/light_nord_template.mm" fit_to_viewport="false"/>

<map_styles>
<stylenode LOCALIZED_TEXT="styles.root_node" STYLE="oval" UNIFORM_SHAPE="true" VGAP_QUANTITY="24 pt">
<font SIZE="24"/>
<stylenode LOCALIZED_TEXT="styles.predefined" POSITION="right" STYLE="bubble">
<stylenode LOCALIZED_TEXT="default" ID="ID_506805493" ICON_SIZE="12 pt" FORMAT_AS_HYPERLINK="false" COLOR="#484747" BACKGROUND_COLOR="#efefef" STYLE="bubble" SHAPE_HORIZONTAL_MARGIN="8 pt" SHAPE_VERTICAL_MARGIN="5 pt" NUMBERED="false" FORMAT="markdownPatternFormat" TEXT_ALIGN="DEFAULT" BORDER_WIDTH_LIKE_EDGE="false" BORDER_WIDTH="1.9 px" BORDER_COLOR_LIKE_EDGE="false" BORDER_COLOR="#8fbcbb" BORDER_DASH_LIKE_EDGE="true" BORDER_DASH="SOLID" VGAP_QUANTITY="2 pt" MAX_WIDTH="10 cm" MIN_WIDTH="0 cm">
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
<stylenode LOCALIZED_TEXT="defaultstyle.floating" BORDER_DASH_LIKE_EDGE="true">
<edge STYLE="hide_edge"/>
<cloud COLOR="#f0f0f0" SHAPE="RECT"/>
</stylenode>
<stylenode LOCALIZED_TEXT="defaultstyle.selection" COLOR="#eceff4" BACKGROUND_COLOR="#bf616a" BORDER_COLOR_LIKE_EDGE="false" BORDER_COLOR="#bf616a"/>
</stylenode>
<stylenode LOCALIZED_TEXT="styles.user-defined" POSITION="right" STYLE="bubble">
<stylenode LOCALIZED_TEXT="styles.important" ID="ID_915433779" BORDER_COLOR="#bf616a" FORMAT="markdownPatternFormat">
<icon BUILTIN="yes"/>
<arrowlink COLOR="#bf616a" TRANSPARENCY="255" DESTINATION="ID_915433779" STARTINCLINATION="66.75 pt;-21.75 pt;" ENDINCLINATION="66.75 pt;3.75 pt;"/>
<font NAME="Ubuntu" SIZE="14"/>
<edge COLOR="#bf616a"/>
</stylenode>
</stylenode>
<stylenode LOCALIZED_TEXT="styles.AutomaticLayout" POSITION="right" STYLE="bubble">
<stylenode LOCALIZED_TEXT="AutomaticLayout.level.root" COLOR="#ffffff" BACKGROUND_COLOR="#484747" STYLE="bubble" SHAPE_HORIZONTAL_MARGIN="10 pt" SHAPE_VERTICAL_MARGIN="10 pt" FORMAT="STANDARD_FORMAT">
<font SIZE="18"/>
</stylenode>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,1" COLOR="#eceff4" BACKGROUND_COLOR="#d08770" STYLE="bubble" SHAPE_HORIZONTAL_MARGIN="8 pt" SHAPE_VERTICAL_MARGIN="5 pt" FORMAT="STANDARD_FORMAT">
<font SIZE="16"/>
</stylenode>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,2" COLOR="#3b4252" BACKGROUND_COLOR="#ebcb8b" FORMAT="STANDARD_FORMAT">
<font SIZE="14"/>
</stylenode>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,3" COLOR="#2e3440" BACKGROUND_COLOR="#a3be8c" FORMAT="STANDARD_FORMAT">
<font SIZE="12"/>
</stylenode>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,4" COLOR="#2e3440" BACKGROUND_COLOR="#b48ead" FORMAT="STANDARD_FORMAT">
<font SIZE="11"/>
</stylenode>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,5" COLOR="#e5e9f0" BACKGROUND_COLOR="#5e81ac" FORMAT="STANDARD_FORMAT">
<font SIZE="11"/>
</stylenode>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,6" BACKGROUND_COLOR="#81a1c1" FORMAT="STANDARD_FORMAT">
<font SIZE="10"/>
</stylenode>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,7" BACKGROUND_COLOR="#88c0d0" FORMAT="STANDARD_FORMAT">
<font SIZE="10"/>
</stylenode>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,8" BACKGROUND_COLOR="#8fbcbb" FORMAT="STANDARD_FORMAT">
<font SIZE="10"/>
</stylenode>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,9" BACKGROUND_COLOR="#d8dee9" FORMAT="STANDARD_FORMAT">
<font SIZE="10"/>
</stylenode>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,10" BACKGROUND_COLOR="#e5e9f0" FORMAT="STANDARD_FORMAT">
<font SIZE="9"/>
</stylenode>
</stylenode>
</stylenode>
</map_styles>
</hook>
<node TEXT="购买的彩票信息&#xd;&#xa;```c&#xd;&#xa;typedef struct{&#xd;&#xa;&#x9;int issue;//发行期号&#xd;&#xa;&#x9;int id;//单张彩票唯一标识符&#xd;&#xa;&#x9;int lotteryNumber;//开奖号&#xd;&#xa;&#x9;int user;//购买者帐号；&#xd;&#xa;&#x9;int purchased;已购买某一彩票号的注数（单张彩票不能超过5注）；&#xd;&#xa;&#x9;char status;//中奖状态；&#xd;&#xa;&#x9;float bonus;//中奖金额；&#xd;&#xa;}Ticket;&#xd;&#xa;&#xd;&#xa;```" LOCALIZED_STYLE_REF="defaultstyle.floating" POSITION="right" ID="ID_1266032155" CREATED="1664006634822" MODIFIED="1664164472387" VGAP_QUANTITY="2 pt" HGAP_QUANTITY="-530.49999 pt" VSHIFT_QUANTITY="-855.74997 pt" FORMAT="markdownPatternFormat">
<hook NAME="FreeNode"/>
<node TEXT="```c&#xd;&#xa;//彩民账号链表&#xd;&#xa;struct user&#xd;&#xa;{&#xd;&#xa;&#x9;char name[30];&#x9; //账号&#xd;&#xa;&#x9;char passwd[32]; //密码&#xd;&#xa;&#x9;float balance;&#x9; //余额&#xd;&#xa;&#x9;struct user *next;&#xd;&#xa;};&#xd;&#xa;typedef struct user User;&#xd;&#xa;```" LOCALIZED_STYLE_REF="default" ID="ID_530153858" CREATED="1664006634822" MODIFIED="1664098401103" HGAP_QUANTITY="18.5 pt" VSHIFT_QUANTITY="-6 pt" FORMAT="markdownPatternFormat"/>
</node>
<node TEXT="```c&#xd;&#xa;//彩票发行&#xd;&#xa;struct lotteryTicket{&#xd;&#xa;&#x9;unsigned int issue;//发行期号&#xd;&#xa;&#x9;int price;//彩票单价&#xd;&#xa;&#x9;short int status;//开奖状态,0未开奖，1已开奖&#xd;&#xa;    int totalSold;//本期售出总数&#xd;&#xa;    float totalPrize;//本期奖池总额&#xd;&#xa;    struct lotteryTicket *next;&#xd;&#xa;};&#xd;&#xa;typedef struct lotteryTicket LotteryTicket;&#xd;&#xa;&#xd;&#xa;```" LOCALIZED_STYLE_REF="defaultstyle.floating" POSITION="right" ID="ID_126155491" CREATED="1664010493970" MODIFIED="1664164485401" VGAP_QUANTITY="2 pt" HGAP_QUANTITY="-524.99999 pt" VSHIFT_QUANTITY="-548.99998 pt" FORMAT="markdownPatternFormat">
<hook NAME="FreeNode"/>
<node TEXT="```c&#xd;&#xa;//管理员账号链表&#xd;&#xa;struct admin&#xd;&#xa;{&#xd;&#xa;&#x9;char name[30];&#x9; //账号&#xd;&#xa;&#x9;char passwd[32]; //密码&#xd;&#xa;&#x9;struct admin *next;&#xd;&#xa;};&#xd;&#xa;typedef struct admin Admin;&#xd;&#xa;```" ID="ID_908255842" CREATED="1664010521442" MODIFIED="1664164485401" FORMAT="markdownPatternFormat"/>
<node TEXT="```c&#xd;&#xa;//公证员账号链表&#xd;&#xa;struct notary&#xd;&#xa;{&#xd;&#xa;&#x9;char name[30];&#x9; //账号&#xd;&#xa;&#x9;char passwd[32]; //密码&#xd;&#xa;&#x9;struct notary *next;&#xd;&#xa;};&#xd;&#xa;```" ID="ID_410898745" CREATED="1664010770237" MODIFIED="1664098372423" FORMAT="markdownPatternFormat"/>
</node>
<node TEXT="彩票分类" LOCALIZED_STYLE_REF="defaultstyle.floating" POSITION="right" ID="ID_1355533998" CREATED="1664007717429" MODIFIED="1664298423813" VGAP_QUANTITY="2 pt" HGAP_QUANTITY="943.49997 pt" VSHIFT_QUANTITY="-432.74999 pt">
<hook NAME="FreeNode"/>
<node TEXT="中国福利彩票" ID="ID_1570922056" CREATED="1664007721356" MODIFIED="1664011031284"><richcontent TYPE="NOTE" CONTENT-TYPE="xml/">
<html>
  <head>
    
  </head>
  <body>
    <p>
      http://www.cwl.gov.cn/fcpz/fctp/
    </p>
  </body>
</html></richcontent>
<node TEXT="即开型" ID="ID_612201196" CREATED="1664008017699" MODIFIED="1664008020656">
<node TEXT="刮刮乐" ID="ID_952051764" CREATED="1664008170124" MODIFIED="1664008177111"/>
</node>
<node TEXT="乐透型" ID="ID_1480770783" CREATED="1664008021271" MODIFIED="1664008027659">
<node TEXT="双色球" ID="ID_1827850656" CREATED="1664008158271" MODIFIED="1664008162955">
<node TEXT="每周二、周四、周日开奖;&#xa;双色球投注区分为红色球号码区和蓝色球号码区，&#xa;红色球号码区由1-33共三十三个号码组成，&#xa;蓝色球号码区由1-16共十六个号码组成。&#xa;&#xa;投注时选择6个红色球号码和1个蓝色球号码组成一注进行单式投注，&#xa;每注金额人民币2元。 &#xa;&#xa;一等奖 &#x9;浮动 &#x9;&#xa;二等奖 &#x9;浮动 &#x9;&#xa;三等奖 &#x9;3,000元 &#x9;&#xa;四等奖 &#x9;200元 &#x9;&#xa;五等奖 &#x9;10元 &#x9;&#xa;六等奖 &#x9;5元" ID="ID_1037359218" CREATED="1664008249322" MODIFIED="1664009090782" FORMAT="markdownPatternFormat"/>
<node TEXT="一等奖：投注号码与当期开奖号码全部相同（顺序不限，下同），即中奖；&#xd;&#xa;&#xd;&#xa;二等奖：投注号码与当期开奖号码中的6个红色球号码相同，即中奖；&#xd;&#xa;&#xd;&#xa;三等奖：投注号码与当期开奖号码中的任意5个红色球号码和1个蓝色球号码相同，即中奖；&#xd;&#xa;&#xd;&#xa;四等奖：投注号码与当期开奖号码中的任意5个红色球号码相同，或与任意4个红色球号码和1个蓝色球号码相同，即中奖；&#xd;&#xa;&#xd;&#xa;五等奖：投注号码与当期开奖号码中的任意4个红色球号码相同，或与任意3个红色球号码和1个蓝色球号码相同，即中奖；&#xd;&#xa;&#xd;&#xa;六等奖：投注号码与当期开奖号码中的1个蓝色球号码相同，即中奖。" ID="ID_1119537033" CREATED="1664013158536" MODIFIED="1664013162435"/>
</node>
<node TEXT="七彩乐" ID="ID_1022522737" CREATED="1664008165514" MODIFIED="1664008168278"/>
</node>
<node TEXT="数字型" ID="ID_1444951699" CREATED="1664008028235" MODIFIED="1664008034187">
<node ID="ID_1154987694" CREATED="1664008180287" MODIFIED="1664008219935"><richcontent TYPE="NODE">

<html>
  <head>
    
  </head>
  <body>
    <p>
      <b>3D</b>
    </p>
  </body>
</html>
</richcontent>
</node>
</node>
<node TEXT="基诺型" ID="ID_1367843408" CREATED="1664008034592" MODIFIED="1664008041041">
<node TEXT="快乐8" ID="ID_1302189674" CREATED="1664008223713" MODIFIED="1664008230328"/>
</node>
</node>
<node TEXT="体育彩票" ID="ID_984116207" CREATED="1664007744509" MODIFIED="1664007751884">
<node TEXT="超级大乐透" ID="ID_1209166524" CREATED="1664012335850" MODIFIED="1664012344606"/>
<node TEXT="排列3" ID="ID_455102109" CREATED="1664012345135" MODIFIED="1664012348824"/>
<node TEXT="排列5" ID="ID_1644194118" CREATED="1664012349002" MODIFIED="1664012351846"/>
<node TEXT="七星彩" ID="ID_901242281" CREATED="1664012352880" MODIFIED="1664012355999"/>
<node TEXT="足球胜负彩" ID="ID_1104027894" CREATED="1664012356272" MODIFIED="1664012362102"/>
</node>
</node>
<node TEXT="明天先在内存中测试所有功能是否可用&#xa;&#xa;然后再逐一做保存文件的功能" LOCALIZED_STYLE_REF="defaultstyle.floating" POSITION="right" ID="ID_840966934" CREATED="1664470243776" MODIFIED="1664470322536" HGAP_QUANTITY="572.99998 pt" VSHIFT_QUANTITY="-312.74999 pt" FORMAT="markdownPatternFormat">
<icon BUILTIN="flag"/>
<hook NAME="FreeNode"/>
<cloud COLOR="#f0f0f0" SHAPE="RECT"/>
</node>
<node TEXT="" POSITION="right" ID="ID_1898050690" CREATED="1664470292377" MODIFIED="1664470292377"/>
<node TEXT="标识符命名规则&#xd;&#xa;&#xd;&#xa;函数用**大驼峰**&#xd;&#xa;&#xd;&#xa;其它变量名用**小驼峰**" LOCALIZED_STYLE_REF="defaultstyle.floating" POSITION="right" ID="ID_384521895" CREATED="1664031502483" MODIFIED="1664164463789" HGAP_QUANTITY="-726.74998 pt" VSHIFT_QUANTITY="-85.5 pt" COLOR="#000000" BACKGROUND_COLOR="#ffffff">
<hook NAME="FreeNode"/>
</node>
<node TEXT="登录" POSITION="right" ID="ID_339781532" CREATED="1664080216385" MODIFIED="1664080219216">
<node TEXT="管理员界面" ID="ID_200545287" CREATED="1664004353219" MODIFIED="1664293065435">
<icon BUILTIN="25%"/>
<node TEXT="发行彩票" ID="ID_1396798079" CREATED="1664004446982" MODIFIED="1664194067667">
<icon BUILTIN="button_ok"/>
<node TEXT="发行的彩票在内存中，要选择保存才会写入文件" ID="ID_921827313" CREATED="1664381927063" MODIFIED="1664469799707"/>
</node>
<node TEXT="查询彩民信息" ID="ID_429736555" CREATED="1664004485594" MODIFIED="1664275734900">
<icon BUILTIN="button_ok"/>
<node TEXT="根据用户名查询" ID="ID_1653815481" CREATED="1664275718499" MODIFIED="1664275738298">
<icon BUILTIN="button_ok"/>
</node>
<node TEXT="根据余额区间查询" ID="ID_256378149" CREATED="1664275723033" MODIFIED="1664275736595">
<icon BUILTIN="button_ok"/>
</node>
<node TEXT="返回上一级菜单" ID="ID_1987354806" CREATED="1664292657485" MODIFIED="1664292860090">
<icon BUILTIN="button_ok"/>
</node>
</node>
<node TEXT="排序" ID="ID_1539259030" CREATED="1664004492138" MODIFIED="1664292856810">
<icon BUILTIN="button_ok"/>
<node TEXT="根据彩民账号排序" ID="ID_903649892" CREATED="1664292572954" MODIFIED="1664292856811">
<icon BUILTIN="button_ok"/>
</node>
<node TEXT="根据彩民用户余额排序" ID="ID_1070253304" CREATED="1664292586245" MODIFIED="1664292856811">
<icon BUILTIN="button_ok"/>
</node>
<node TEXT="返回上一级菜单" ID="ID_1482348648" CREATED="1664292657485" MODIFIED="1664292856812">
<icon BUILTIN="button_ok"/>
</node>
</node>
<node TEXT="查看发行历史" ID="ID_400939021" CREATED="1664080197605" MODIFIED="1664194368155">
<icon BUILTIN="button_ok"/>
</node>
<node TEXT="账号管理" ID="ID_256425503" CREATED="1664205525270" MODIFIED="1664205528598">
<node TEXT="添加管理员账号" ID="ID_1703031845" CREATED="1664069927821" MODIFIED="1664206407015">
<icon BUILTIN="button_ok"/>
</node>
<node TEXT="删除管理员账号" ID="ID_612673814" CREATED="1664206397022" MODIFIED="1664206412039"/>
<node TEXT="公证员添加" ID="ID_861164949" CREATED="1664069986005" MODIFIED="1664205546080">
<icon BUILTIN="button_ok"/>
</node>
<node TEXT="删除公证员账号" ID="ID_321668421" CREATED="1664206413624" MODIFIED="1664206418708"/>
<node TEXT="返回上一级菜单" ID="ID_738926030" CREATED="1664292657485" MODIFIED="1664292842675"/>
</node>
<node TEXT="保存" ID="ID_992678354" CREATED="1664004494445" MODIFIED="1664298386618">
<icon BUILTIN="flag"/>
<node TEXT="保存彩民账号" ID="ID_833057772" CREATED="1664293079631" MODIFIED="1664451345549">
<node TEXT="正在写保存功能" ID="ID_438921882" CREATED="1664298393008" MODIFIED="1664385207343"/>
</node>
<node TEXT="保存彩票信息" ID="ID_1765137449" CREATED="1664293083270" MODIFIED="1664451341757">
<icon BUILTIN="button_ok"/>
</node>
</node>
<node TEXT="退出登录" ID="ID_690092702" CREATED="1664194345271" MODIFIED="1664204824735">
<icon BUILTIN="button_ok"/>
</node>
</node>
<node TEXT="公证员界面" ID="ID_1976271761" CREATED="1664004587642" MODIFIED="1664293070171">
<node TEXT="开奖" ID="ID_266871431" CREATED="1664004593396" MODIFIED="1664204797352">
<icon BUILTIN="button_ok"/>
</node>
<node TEXT="查看彩票发行历史" ID="ID_1706283334" CREATED="1664004599239" MODIFIED="1664204810383">
<icon BUILTIN="button_ok"/>
</node>
<node TEXT="退出登录" ID="ID_1170745842" CREATED="1664204812801" MODIFIED="1664204817559">
<icon BUILTIN="button_ok"/>
</node>
</node>
<node TEXT="彩民界面" ID="ID_197218013" CREATED="1664004378245" MODIFIED="1664293075079">
<node TEXT="查看个人信息" ID="ID_557055966" CREATED="1664004500430" MODIFIED="1664327746498">
<icon BUILTIN="button_ok"/>
</node>
<node TEXT="修改密码" ID="ID_127038925" CREATED="1664329633593" MODIFIED="1664329645959">
<icon BUILTIN="button_ok"/>
<node TEXT="检验旧密码是否正确，不正确提示重新输入旧密码" ID="ID_1899709402" CREATED="1664004524202" MODIFIED="1664329583684">
<icon BUILTIN="button_ok"/>
</node>
<node TEXT="旧密码正确，检验两次新密码是否一致，一致则替换当前密码，退出登录" ID="ID_559145556" CREATED="1664329584377" MODIFIED="1664329645961">
<icon BUILTIN="button_ok"/>
</node>
</node>
<node TEXT="账户充值" ID="ID_1374348353" CREATED="1664004529736" MODIFIED="1664004538889">
<node TEXT="可以充值" ID="ID_504755034" CREATED="1664329527082" MODIFIED="1664329549599">
<icon BUILTIN="button_ok"/>
</node>
<node TEXT="购买彩票时余额不足要提示" ID="ID_1956043831" CREATED="1664329530249" MODIFIED="1664381796387">
<icon BUILTIN="button_ok"/>
</node>
<node TEXT="充值成功后自动保存数据到文件" ID="ID_1066717046" CREATED="1664440123048" MODIFIED="1664469560536" BACKGROUND_COLOR="#33ff33">
<icon BUILTIN="button_cancel"/>
</node>
</node>
<node TEXT="下注" ID="ID_522913412" CREATED="1664004532908" MODIFIED="1664381785311">
<icon BUILTIN="button_ok"/>
<node TEXT="彩民可选择下注数、下注方式" ID="ID_511224934" CREATED="1664337636159" MODIFIED="1664381865844">
<icon BUILTIN="button_ok"/>
<node TEXT="自选号码" ID="ID_432572419" CREATED="1664337659126" MODIFIED="1664337662575"/>
<node TEXT="机选号码" ID="ID_581878574" CREATED="1664337662703" MODIFIED="1664381791483">
<icon BUILTIN="button_ok"/>
<node TEXT="下注完之后，更新奖池信息" ID="ID_981703883" CREATED="1664451874425" MODIFIED="1664451889108"/>
<node TEXT="选完之后记录到文件" ID="ID_1524712711" CREATED="1664469571023" MODIFIED="1664469579512">
<icon BUILTIN="button_cancel"/>
</node>
</node>
</node>
<node TEXT="提示彩民相关彩票信息，例如售价、期数等，所有彩民登录后看到相同的彩票信息" ID="ID_197612224" CREATED="1664381814209" MODIFIED="1664381910772">
<icon BUILTIN="button_ok"/>
</node>
<node TEXT="确定后从账户余额中扣除相应金额（余额不足须提示）" ID="ID_500153970" CREATED="1664381856389" MODIFIED="1664381910770">
<icon BUILTIN="button_ok"/>
</node>
</node>
<node TEXT="注销" ID="ID_697807746" CREATED="1664004542769" MODIFIED="1664329651222">
<icon BUILTIN="button_ok"/>
<node TEXT="注销前，提示风险，再次确认！" ID="ID_1755562616" CREATED="1664329652274" MODIFIED="1664364522016">
<icon BUILTIN="button_ok"/>
</node>
</node>
<node TEXT="查看购买记录" ID="ID_932544931" CREATED="1664004547442" MODIFIED="1664469647824">
<icon BUILTIN="button_cancel"/>
</node>
</node>
</node>
<node TEXT="注册新用户" POSITION="right" ID="ID_1077785032" CREATED="1664004382103" MODIFIED="1664194025908" VGAP_QUANTITY="2 pt">
<icon BUILTIN="button_ok"/>
<node TEXT="彩民注册" ID="ID_1914263206" CREATED="1664069918189" MODIFIED="1664194022596">
<icon BUILTIN="button_ok"/>
<node TEXT="1. 检查用户名是否唯一&#xa;2. 检查用户名密码长度是否满足条件&#xa;3. 检查两次输入的密码是否一致&#xa;&#xa;都满足则写入链表" ID="ID_1944753273" CREATED="1664080330086" MODIFIED="1664080398602" FORMAT="markdownPatternFormat"/>
<node TEXT="注册完自动保存账号到文件" ID="ID_90757055" CREATED="1664451356269" MODIFIED="1664451367204">
<icon BUILTIN="button_ok"/>
</node>
</node>
<node TEXT="返回主菜单" ID="ID_1463729098" CREATED="1664080145945" MODIFIED="1664080322247">
<icon BUILTIN="button_ok"/>
<richcontent TYPE="NOTE" CONTENT-TYPE="xml/">
<html>
  <head>
    
  </head>
  <body>
    <p>
      return结束当前函数
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node TEXT="退出主程序" POSITION="right" ID="ID_1319705561" CREATED="1664080227049" MODIFIED="1664080432577">
<icon BUILTIN="button_ok"/>
</node>
</node>
</map>
