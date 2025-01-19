<?php
header('Content-Type: application/json; charset=utf-8');

$file = file_get_contents('data.json');
$data = json_decode($file, true);

$errors = [];
$validGroups = ['М', 'ПМ', 'ОКН', 'ЯКН'];


if (empty($data['name'])) {
    $errors['name'] = "Името на учебния предмет е задължително поле.";
} elseif (mb_strlen($data['name']) < 2 || mb_strlen($data['name']) > 150) {
    $errors['name'] = "Името на предмета трябва да е между 2 и 150 символа.";
}


if (empty($data['teacher'])) {
    $errors['teacher'] = "Името на преподавателя е задължително поле.";
} elseif (mb_strlen($data['teacher']) < 3 || mb_strlen($data['teacher']) > 200) {
    $errors['teacher'] = "Името на преподавателя трябва да е между 3 и 200 символа.";
}


if (empty($data['description'])) {
    $errors['description'] = "Описанието е задължително поле.";
} elseif (mb_strlen($data['description']) < 10) {
    $errors['description'] = "Описанието трябва да е с дължина поне 10 символа, а вие сте въвели " . mb_strlen($data['description']) . ".";
}


if (empty($data['group'])) {
    $errors['group'] = "Групата е задължително поле.";
} elseif (!in_array($data['group'], $validGroups, true)) {
    $errors['group'] = "Невалидна група, изберете една от М, ПМ, ОКН и ЯКН.";
}


if (!isset($data['credits'])) {
    $errors['credits'] = "Кредитите са задължително поле.";
} elseif (!filter_var($data['credits'], FILTER_VALIDATE_INT, ["options" => ["min_range" => 1]])) {
    $errors['credits'] = "Кредитите трябва да са цяло положително число.";
}

if (empty($errors)) {
    echo json_encode(["success" => true], JSON_UNESCAPED_UNICODE);
} else {
    echo json_encode(["success" => false, "errors" => $errors], JSON_UNESCAPED_UNICODE);
}
?>
