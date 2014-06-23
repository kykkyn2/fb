<?php include_once 'lib/init.inc';?>

<!DOCTYPE html>

<html>
<head>
	<meta charset="utf-8"> 
	<meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0, user-scalable=no"/>
	<meta name="format-detection" content="telephone=no">
	<title>FB SAMPLE</title>
	<style type="text/css">
	.unlike{position:relative;width:360px;height:630px;margin:0px auto;background: url(common/images/m_unlike.png) no-repeat;background-size:100%;}
	.unlike .box_unlike{position: absolute;top:210px;left:160px;}
	</style>
</head>
<body style="overflow:hidden;">
	<div id="fb-root"></div>

	<!-- 랜딩페이지 -->
	<div class="wrap_landing" style="display:;">
		<a href="#"><img src="common/images/m_bridge.png" alt="이벤트에 참여하려면 화면을 터치해 주세요." /></a> 
	</div>
	<!-- //랜딩페이지 -->

	<!-- 언라이크 -->
	<div class="unlike" style="display:none;">
		<div class="box_unlike">
			<fb:like href="https://www.facebook.com/jhpark15/app_224920567690694" send="false" layout="button_count" width="230" height="35" colorscheme="light" font="arial" action="like" show_faces="false" style="width:57px;height:23px;overflow:hidden;" allowTransparency="true"></fb:like>
		</div>		
	</div>
	<!-- //언라이크 -->

	<script>
		var sAccessToken = ""; // access token 변수
		var sUID = "";
		var oFBParam = {
			apikey : '<?php echo APP_ID;?>', // APP ID
			tabUrl :'<?php echo TAB_URL;?>', // TAB URL
			appsUrl : '<?php echo APPS_URL;?>', // TAB URL
			redirecturl : '<?php echo TAB_URL;?>', // REDIRECT URL
			perms : '<?php echo PERMS;?>', // Permissions
			oauth : true, // OAuth 2.0 사용 여부
			type : 'PC', // 페이지 타입 (PC, MOBILE)
			fan : '<?php echo $isFan?>',	//페이지 좋아요 유무
			pageId : '<?php echo PAGE_ID?>'	//페이지 좋아요 유무
		};
	</script>
	<script charset="UTF-8" type="text/javascript" src="common/util/jquery-1.8.0.min.js"></script>
	<script charset="UTF-8" type="text/javascript" src="common/js/facebook.js"></script>
	<script charset="UTF-8" type="text/javascript" src="common/js/function.js"></script>
	<script charset="UTF-8" type="text/javascript" src="common/js/tab.js"></script>
	<script charset="UTF-8" type="text/javascript" src="common/js/sns.js"></script>
	<script charset="UTF-8" type="text/javascript" src="common/js/script.js"></script>
	<script charset="UTF-8" type="text/javascript" src="common/util/kakao.link.js"></script>

	

</body>
</html>