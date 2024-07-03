const express = require('express');
const bodyParser = require('body-parser');
const { diffLines } = require('diff');

const app = express();
const port = 5500;

// 使用body-parser中间件来解析请求体
app.use(bodyParser.text());

// 处理POST请求，比对两段代码
app.post('/compare', (req, res) => {
    const { code1, code2 } = req.body;

    const diff = diffLines(code1, code2);
    res.json(diff);
});

app.listen(port, () => {
    console.log(`Server is running on port ${port}`);
});
