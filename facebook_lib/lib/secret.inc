<?php include_once 'init.inc';?>
<?php
/*
암호화 및 복호화를 위한 함수
- 인자값 : $action => encrypt, decrypt, $string => 암호화 및 복호화를 할 인자값
- 암호화 : encrypt_decrypt("encrypt", $String)
- 복호화 : encrypt_decrypt("decrypt", $String)
*/
function encrypt_decrypt($action, $string) {
    $output = false;

	//AES-256-CBC으로 암호화 및 복호화
    $encrypt_method = "AES-256-CBC";
	//암호화 및 복호화시 필요한 키값
    $secret_key = 'test';
    //$secret_key = 'cjtlj';
    //$secret_iv = 'cjtlj1!';
    $secret_iv = 'test1!';

    //키값을 SHA256 방식으로 암호화
    $key = hash('sha256', $secret_key);
    $iv = hash('sha256', $secret_iv);

    if( $action == 'encrypt' ) { //사용자 정보를 암호화
		$output = openssl_encrypt($string, $encrypt_method, $key, $iv);
		$output = base64_encode($output);
    }
    else if( $action == 'decrypt' ){//사용자 정보를 복호화
        $output = $decryptedMessage = openssl_decrypt(base64_decode($string), $encrypt_method, $key, $iv);
    }

    return $output;
}

?>