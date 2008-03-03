require 'dbus'
bus = DBus::SessionBus.instance
service = bus.service('org.laptop.Activityabc')
object = service.object('/org/laptop/Activity/abc')
puts "introspecting"
object.introspect
puts "introspected"
object.default_iface('org.laptop.Activity')
object.TakeScreenshot
