<?php
	include_once 'lib/init.inc';
	
	function useragent() {

		//사용자 디바이스 정보
		$useragent = strtolower($_SERVER['HTTP_USER_AGENT']);
		
		if(strchr($useragent,"iphone") || strchr($useragent,"ipod") || strchr($useragent,"android") || strchr($useragent, "blackberry") || strchr($useragent, "window mobile") ){
			
			//모바일 디바이스일 경우		
			header('Location: '. MOBILE_URL);
		}else{
			
			//PC일 경우
?>			
			<script>
				top.location.href='<?php echo TAB_URL?>';
			</script>
<?php
		}
	}
	useragent();
?>