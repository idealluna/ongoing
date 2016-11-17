#!/usr/bin/env python

import distutils.core

name = 'hello'

distutils.core.setup(name=name,
    version='1.0',
    author="Packager Tester",
    author_email="packger.tester@tester.com",
    url="http://test.cn",
    description="hello test for setup.py to rpm",
    long_description="hello test for setup.py to rpm",
    license="GPLv2",

    scripts=[name],
    data_files=[
        ('/usr/share/man/man1', [name + '.1.gz']),
    ],
)
