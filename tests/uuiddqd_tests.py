from nose.tools import *
import uuiddqd

class TestUuiddqd(object):
  @classmethod
  def setup_class(klass):
    klass.uuid = uuiddqd.generate()

  def test_length(self):
    assert_equal(36, len(self.uuid))

  def test_random(self):
    another_uuid = uuiddqd.generate()
    assert_not_equal(self.uuid, another_uuid)
