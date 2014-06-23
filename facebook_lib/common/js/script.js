$(function(){
	
	//웹
	$("#event_start").click(function(){
		//권한 획득 확인
		fbAuth( function( res ){
			console.log(res);
		});
	});
	
	//모바일
	$(".wrap_landing").click(function(){
		
		tab.setAuth(function(res){
			//페이지 아이디
			var sPageId = oFBParam.pageId;
			
			oFB.mLikeCheck(sPageId,function(res){
				
				if(res.data.length == 0){
					$(".wrap_landing").hide();
					$(".unlike").show();
				}else{
					c.log("메인 고고");
				}
			});
			
			
		});
	});
	
	/*
		//권한 받기
		fbAuth( function( res ){
			
		});
	*/
	
	
	$("#test_start").click(function(){
		
		
		snsShare ( 'tw' , function( res ){
			console.log(res);
		});
		
	});
	
	
});
