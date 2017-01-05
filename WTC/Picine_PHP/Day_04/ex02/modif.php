<?php
    if ($_POST['login'] && $_POST['oldpw'] && $_POST['newpw'] && $_POST['submit'] && $_POST['submit'] === "OK")
    {
        $account = unserialize(file_get_contents('../private/passwd'));
        if ($account)
        {
            $exists = 0;
            foreach($account as $sponge => $bob)
            {
                if ($bob['login'] === $_POST['login'] && $bob['passwd'] === hash('whirlpool', $_POST['oldpw']))
                {
                    $exists = 1;
                    $account[$sponge]['passwd'] = hash('whirlpool', $_POST['newpw'])
                }
            }
            if ($exists)
            {
                file_put_contents('../private/passwd', serialize($account));
                echo "OK\n";
            }
            else
            {
                echo "ERROR\n";
            }
        }
        else
            echo "ERROR\n";
    }
    else
        echo "ERROR\n";
?>