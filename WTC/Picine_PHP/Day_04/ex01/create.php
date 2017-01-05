<?PHP
    if($_POST['login'] && $_POST['passwd'] && $_POST['submit'] && $_POST['submit'] === "OK")
    {
        if (!file_exists('../private'))
            mkdir("../private");
        if (!file_exists('../private/passwd'))
            file_put_contents('../private/passwd', NULL);
        $account = unserialize(file_get_contents('../private/passwd'));
        if ($account)
        {
            $exists = 0;
            foreach($account as $sponge => $bob)
            {
                if ($bob['login'] === $_POST['login'])
                    $exists = 1;
            }
        }
        if ($exists)
        {
            echo "ERROR\n";
        }
        else
        {
            $tmp['login'] = $_POST['login'];
            $tmp['passwd'] = hash('whirlpool', $_POST['passwd']);
            $account[] = $tmp;
            file_put_contents('../private/passwd', serialize($account));
            echo "OK";
        }
    }
    else
        echo "ERROR\n";
?>