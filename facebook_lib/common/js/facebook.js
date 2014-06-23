/*
 * 페이스북 기본 셋팅 정의
 */
var oFB = (function(param) {
	var fbApiInitialized = false;
	var options = {
		apikey : param.apikey || null
		,tabUrl : param.tabUrl ||null
		,appsUrl : param.appsUrl || null
		,perms : param.perms || null		
		,redirecturl : param.redirecturl || null
		,oauth : param.oauth || false		
		,pageType : param.pageType || ''		
		
		,status : param.status || true 
		,cookie : param.cookie || true 
		,xfbml : param.xfbml || true
		,pageType : param.type || null
		,isFan : param.fan || null
		,channelUrl : param.channelUrl || document.location.protocol + '//' + document.location.hostname + '/channel.html'
		
	};	
    
	function _fbEnsureInit(callback) {
        if (!fbApiInitialized) {
            setTimeout(function() { _fbEnsureInit(callback); }, 100);
        } else {
            if (callback) {  
              callback(); 
            }
        }
	}

    // Facebook Javascript SDK 로딩
	function fbConnect() {
		
		window.fbAsyncInit = function() {
			FB.Event.subscribe('auth.login', function(response) {
				fbApiInitialized = true;
				FB.Canvas.setAutoGrow();
			});
			FB.init({
				appId      : options.apikey, // App ID
				channelURL : options.channelUrl, // Channel File
				status     : options.status, // check login status
				cookie     : options.cookie, // enable cookies to allow the server to access the session
				oauth      : options.oauth, // enable OAuth 2.0
				xfbml      : options.xfbml  // parse XFBML
			});
			
			FB.Canvas.setAutoGrow();
			
			//Additional initialization code such as adding Event Listeners goes here
		};
	};

	(function(d) {
		var js, id = 'facebook-jssdk';if(d.getElementById(id)) {return;}
		js = d.createElement('script');js.id = id;js.async = true;js.src = "//connect.facebook.net/ko_KR/all.js";
		d.getElementsByTagName('head')[0].appendChild(js);
		if(js.readyState){
			//IE용 script 레디 상태 체크
			js.onreadystatechange = function() {
				if(this.readyState == 'complete' || this.readyState == 'loaded') {
					fbConnect();
				}
			};
		}else{
			js.onload = function(){
				fbConnect();
			} 
		}
	}(document));
	
    
    //Facebook 로그인 및 ALLOW
	function _login(cb){		
	  if(options.pageType == "PC" || options.pageType == ""){
			top.location.href='https://www.facebook.com/dialog/oauth/?'
					  +'scope='+options.perms+'&'
					  +'client_id='+options.apikey+'&'
					  +'redirect_uri='+options.redirecturl+'&'
					  +'response_type=token';         
	  }else if(options.pageType == "MOBILE"){
			top.location.href='https://m.facebook.com/dialog/oauth/?'
					  +'scope='+options.perms+'&'
					  +'client_id='+options.apikey+'&'
					  +'redirect_uri='+options.redirecturl+'&'
					  +'response_type=token';            
	  }
	}
	
	return {
		fbEnsureInit : function(callback){
			_fbEnsureInit(callback);
		},
		//sns 기능들
		snsPost : function(param, cb){
			var aAttachment = null;
			switch(param.mediaType){
				case 'image' :
					aAttachment = {
						method: 'feed',
	                    link: param.imgLink,
	                    name: param.title,
	                    picture: param.imgSrc,
	                    caption: param.caption
					}
					FB.ui(aAttachment,function(res){
						
					});
					break;
				default :
					aAttachment = {
						'name' : param.title,
						'href' : param.imgLink,
						'description' : param.publishMsg,
						'caption' : param.caption
					};
					break;
			}
		},
		//권한 체크
		getPermCheck : function(sPerms,callback){
			var flag = false;
			var sFQL = "SELECT "+sPerms+" FROM permissions WHERE uid = me()";
			FB.api({
				method : 'fql.query',
				query : sFQL
			},function(res){
				if(res[0].publish_stream != "1"){
					flag = false;
					return callback(flag);
				}else{
					flag = true;
					return callback(flag);
				}
			});
		},
		//권한 얻기
		setPerm : function(sPerms,callback){
			FB.login(function(res){
       			return callback(res);
       	 	},{scope:sPerms});
		},
		//FQL callback
		getFQL : function(sFQL,callback){
			FB.api("/fql?q="+encodeURIComponent(sFQL),function(res){
				return callback(res);
			});
		},
		//친구초대
		invite : function(callback){
			FB.ui({
			  method: 'apprequests',
		      title: 'hi title',
		      message: 'there is message!',
			},callback);
		},
		//API Callback
		getAPI : function(sAPI,callback){
			FB.api(sAPI,function(res){
				return callback(res);
			});
		},
		//로그인 상태 체크
		getAuthCheck : function(callback){
			FB.getLoginStatus(function(res){
				return callback(res);
			});
		},
		//모바일 좋아요 체크
		mLikeCheck : function(sPageId,callback){
			var sFQL = 'SELECT page_id FROM page_fan WHERE page_id = '+sPageId+' AND uid = me()';
			oFB.getFQL(sFQL,function(res){
				return callback(res);
			});
		}
	};
})(oFBParam);